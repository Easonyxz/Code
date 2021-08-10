import requests
from bs4 import BeautifulSoup
import re
from fake_useragent import UserAgent
from time import sleep
from random import choice
from urllib.parse import quote

def main():
    #getUserAgent()
    #getProxyIpPool()
    # ip = getProxyIP()
    # print(ip)
    #getBossJobs()
    #askUrl()
    # ip = getProxyIP()
    # print(ip)
    # position = quote('测试工程师')
    # cityNum = '101280600'
    # url = getUrl(position, cityNum)
    getBossJobs(url)
    job_desc = getJobDesc('https://www.zhipin.com/job_detail/e90f31d8c5f61f9d0Xx42tS0EFM~.html')

    print(job_desc)
    # getBossJobs()

def getUserAgent():
    UA = UserAgent()
    ua = UA.random
    return ua

def getProxyIpPool():
    """
    从代理IP网站爬取多个代理IP，把IP放在列表data中
    :return:
    """
    data = []
    url = 'https://www.kuaidaili.com/free'
    userAgent = getUserAgent()
    cookie = 'channelid=0; sid=1596648322236711; _ga=GA1.2.333258184.1596648323; _gid=GA1.2.1094813415.1597158985; Hm_lvt_7ed65b1cc4b810e9fd37959c9bb51b31=1596648323,1596822836,1597158985; Hm_lpvt_7ed65b1cc4b810e9fd37959c9bb51b31=1597158985'

    header = {'User-Agent':userAgent,'Cookie':cookie,'Upgrade-Insecure-Requests':'1'}
    res = requests.get(url=url, headers=header)
    #print(res.text)
    html = res.text
    soup = BeautifulSoup(html, 'html.parser')
    table = soup.find_all('table', class_='table-bordered')
    for index in range(len(table)):

        tds = table[index]
        tds = str(tds)
        #print(tds)
        ip = re.findall(r'<td data-title="IP">(.*?)<',tds)
        port = re.findall(r'<td data-title="PORT">(.*?)<',tds)
        #print(ip[0])
        proxyip = str(ip[0]) + ":" + str(port[0])
        data.append(proxyip)

    #print(data)
    sleep(3)
    return data

def getProxyIP():
    """
    随机获取代理IP
    :return:
    """
    data = getProxyIpPool()
    proxyip = choice(data)
    proxies = {
        "http": "http://" + proxyip
    }
    #print(type(proxies))
    return proxies

def getCookies():
    with open(r"bosscookies.txt", "r") as rstream:
        cookies = rstream.readlines()[0]
        return cookies

def getUrl(position, cityNum):
    position = quote(position)
    url = 'https://www.zhipin.com/job_detail/?query=' + position + '&city=' + cityNum + '&industry=&position='
    return url

def askUrl(url):

    proxies = getProxyIP()
    userAgent = getUserAgent()
    accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9"
    acceptencoding = "gzip, deflate, br"
    acceptlanguage = "zh-CN,zh;q=0.9"
    cachecontrol = "max-age=0"
    cookie = getCookies()
    referer = "https://www.zhipin.com/"
    #referer = 'https://www.zhipin.com/job_detail/?query=%E6%B5%8B%E8%AF%95%E5%B7%A5%E7%A8%8B%E5%B8%88&city=101280600&industry=&position='
    secfetchdest = "document"
    secfetchmode = "navigate"
    secfetchsite = "same - origin"
    secfetchuser = "?1"
    upgradeinsecurerequests = "1"
    #"referer": referer,
    headers = {"accept":accept, "accept-encoding":acceptencoding, "accept-language":acceptlanguage, "cache-control":cachecontrol,
               "referer": referer,"cookie":cookie,"sec-fetch-dest":secfetchdest, "sec-fetch-mode":secfetchmode, "sec-fetch-site":secfetchsite,
               "sec-fetch-user":secfetchuser, "upgrade-insecure-requests":upgradeinsecurerequests,"user-agent":userAgent}
    #print(headers)
    res = requests.get(url=url, headers=headers, proxies=proxies)

    return res.text

def getHtml(htmlname):
    """
    读出HTML文件
    :return: html
    """
    with open(htmlname, "r",encoding='UTF-8') as htmlstream:
        html = htmlstream.read()
        return html

def getBossJobs(position, cityNum):
    """
    获取boss直聘上前10页的某个职位的岗位信息
    爬取数据包括：职位title，详细职位信息链接，办公地点，薪资，发布时间，招聘要求，招聘公司
    :return:
    """

    start_html = 'https://www.zhipin.com'
    datalist = []   #存放所有数据
    #访问boss网站
    url = getUrl(position, cityNum)
    html = askUrl(url)

    soup = BeautifulSoup(html, "html.parser")
    for item in soup.find_all('div',class_="job-primary"):
        data = []   #存放每一个item中所需要的数据
        #print(type(item))
        job_name_info = item.find_all('span', class_ = 'job-name')[0]
        #print(type(job_name_info))
        #用正则获取具体信息
        job_link = start_html + job_name_info.find_all('a')[0]['href']  #职位详细信息链接
        job_title = job_name_info.find_all('a')[0]['title']  #职位title
        data.append(job_title)
        data.append(job_link)
        #print(job_link)
        job_area = re.findall('<span class="job-area">(.*?)</span>',str(item))[0]  #工作地点
        data.append(job_area)
        job_salary = re.findall('<span class="red">(.*?)</span>', str(item))[0]   #薪资
        data.append(job_salary)
        job_salary = re.findall('<span class="red">(.*?)</span>', str(item))[0]  # 薪资
        data.append(job_salary)
        job_pub_time = re.findall('<span class="job-pub-time">(.*?)</span>', str(item))[0]  # 发布时间
        data.append(job_pub_time)
        company_info = item.find_all('h3',class_="name")[1]
        company_name = company_info.find_all('a')[0]['title']   #招聘公司
        data.append(company_name)
        #job_description = getJobDesc(job_link)   #职位描述信息
        #sleep(3)   #每次访问完后要睡眠3秒钟，以免因快速访问被反爬
        #print(job_description)
        # data.append(job_description)
        datalist.append(data)
    print(datalist)
    return datalist

def getJobDesc(url):
    # 职位描述
    #job_detail_html = getHtml("job_detail.html")
    job_detail_html = askUrl(url)
    print(job_detail_html)

    job_detail_soup = BeautifulSoup(job_detail_html, "html.parser")
    job_description = job_detail_soup.find_all('div', class_="text")[0]   #爬取职位描述信息
    # print(type(job_description))
    #print(job_description)
    #job_desc = re.findall(r'>(.*?)', str(job_description))
    job_desc = job_description.text.replace('\n', "").strip()     #对职位描述信息进行去除换行和空格的处理
    #print(job_desc)
    return job_desc

if __name__ == '__main__':
    main()