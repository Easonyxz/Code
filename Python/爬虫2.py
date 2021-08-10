# !/usr/bin/env python
# -*- coding:utf-8 -*-
# Author锛歜lning
# File锛歍encentJob.py
 
import random
import time
from urllib import parse
from fake_useragent import UserAgent
import requests
 
class TencentJobSpier:
    def __init__(self):
        # timestamp锛氭椂闂存埑锛沰eyword锛氭煡璇㈠弬鏁帮紱pageIndex锛氭煡璇㈤〉闈�
        self.url = 'https://careers.tencent.com/tencentcareer/api/post/Query?timestamp={}&countryId=&cityId=&bgIds=&productId=&categoryId=&parentCategoryId=&attrId=&keyword={}&pageIndex={}&pageSize=10&language=zh-cn&area=cn'
 
        # 浜岀骇椤甸潰鐨刄RL鍦板潃
        self.two_url = 'https://careers.tencent.com/tencentcareer/api/post/ByPostId?timestamp={}&postId={}&language=zh-cn'
 
        # 鏋勫缓璇锋眰澶�(浣跨敤 fake_useragent 鏋勫缓闅忔満鐨勮姹傚ご)
        self.header = {'User-Agent': UserAgent().random}
 
        # 瀛樺偍鎵€鏈夌殑 鑱屼綅鏁版嵁
        self.jobData_list = []
        
 
 
 
    def get_html(self, url):
        '''
            鏍规嵁涓嶅悓鐨勮姹俇RL鍜岃姹傚ご淇℃伅鑾峰彇瀵瑰簲鐨勯〉闈SON鏍煎紡鏁版嵁
        :param url: 鍙戦€佽姹傜殑URL鍦板潃
        :param headers: 涓€绾ч〉闈㈡垨浜岀骇椤甸潰鐨勮姹傚ご淇℃伅
        :param params: 涓€绾ч〉闈㈡垨浜岀骇椤甸潰鐨勮姹傚弬鏁�
        :return: 璇锋眰鎴愬姛杩斿洖HTML椤甸潰鐨凧SON鏍煎紡鏁版嵁锛屽惁鍒欒繑鍥濶one
        '''
        try:
            response = requests.get(url=url, headers=self.header, timeout=5)
            if response.status_code == 200:
                return response.json()
            else:
                return None
        except Exception as e:
            print(f'璇锋眰寮傚父锛歿e}')
            return None
 
 
    def parse_one_html(self, kword, page, id_list):
        '''
            瑙ｆ瀽鑾峰彇鑱屼綅鏁版嵁鐨処D鍙凤紝骞跺瓨鍌ㄨ嚦self.jobID_list鍒楄〃涓�
        :param kword: 鏌ヨ鐨勮亴浣嶅悕绉�
        :param page: 璇锋眰鐨勯〉鐮佹暟
        :param id_list: 瀛樺偍姣忛〉鎵€鏈夌殑鑱屼綅ID鍒楄〃
        :return: None
        '''
        timestamp = int(time.time() * 1000)
        keyword = parse.quote(kword)
        url = self.url.format(timestamp, keyword, page)
        one_html_data = self.get_html(url)
        if one_html_data:
            datas = one_html_data["Data"]["Posts"]
            for data in datas:
                id_list.append(data["PostId"])
               
 
 
    def parse_two_html(self, PostID):
        '''
            瑙ｆ瀽浜岀骇椤甸潰鏁版嵁锛屽瓨鍌ㄨ嚦self.jobData_list鍒楄〃涓�
        :param PostID: 鑱屼綅鐨処D鍙�
        :return: None
        '''
        timestamp = int(time.time() * 1000)
        url = self.two_url.format(timestamp, PostID)
        two_html_data = self.get_html(url)
        if two_html_data:
            job_name = two_html_data["Data"]["RecruitPostName"]
            job_location = two_html_data["Data"]["LocationName"]
            job_category = two_html_data["Data"]["CategoryName"]
            job_responsibility = two_html_data["Data"]["Responsibility"]
            job_requirement = two_html_data["Data"]["Requirement"]
            job_lastUpdateTime = two_html_data["Data"]["LastUpdateTime"]
            self.jobData_list.append((job_name, job_location, job_category, job_responsibility, job_requirement, job_lastUpdateTime))
 
 
    def get_total(self, kword):
        '''
            鑾峰彇棣栭〉鐨勮亴浣嶆€绘暟骞惰繑鍥�
        :param kword: 鏌ヨ涓殑鑱屼綅鍏抽敭瀛�
        :return: 鑱屼綅鐨勬€绘嫑鑱樻暟閲�
        '''
        timestamp = int(time.time() * 1000)
        keyword = parse.quote(kword)
        url = self.url.format(timestamp, keyword, 1)
        html = self.get_html(url)
        return html["Data"]["Count"]
 
 
    # 涓诲嚱鏁�
    def main(self):
        kword = input('璇疯緭鍏ヨ鏌ヨ鐨勮亴浣嶏細')
        total = self.get_total(kword)
        page = total // 10 + 1
        for i in range(1, total+1):
            print(f'姝ｅ湪鐖彇绗� {i} 椤垫暟鎹�....')
            id_list = []  # 鐢变簬姣忔璇锋眰闇€瑕佸瓨鍌ㄦ湰椤电殑鑱屼綅ID鍋氫负鐖彇瀵硅薄锛屽垯姣忔寰幆鍒欓渶瑕佹竻绌�
            self.parse_one_html(kword, i, id_list)
            for postID in id_list:
                print(f'姝ｅ湪璇锋眰鐨勮亴浣岻D涓猴細{postID}')
                self.parse_two_html(postID)
              
                time.sleep(random.uniform(1,3))   # 姣忎釜璇︾粏椤典紤鐪�
            time.sleep(random.uniform(1, 3))     # 姣忔寰幆璇锋眰涓嬩竴椤典紤鐪�
        print(self.jobData_list, len(self.jobData_list))
 
 
if __name__ == '__main__':
    tencentJob = TencentJobSpier()
    tencentJob.main()