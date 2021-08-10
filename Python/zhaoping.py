# encoding=gbk
import requests
import json
import csv
from urllib.parse import urlencode
import time
 
def saveHtml(file_name,file_content): #����conten����Ϊhtml�ļ�
 with open(file_name.replace('/','_')+'.html','wb') as f:
  f.write(file_content)
 
def GetData(url,writer):#�����������ݱ���ΪCSV�ļ�
 response= requests.get(url)
 data=response.content
 saveHtml('zlzp',data) #����html�ļ�
 jsondata=json.loads(data)
 dataList=jsondata['data']['results']
 #print(jsondata)
 for dic in dataList:
  jobName=dic['jobName']  #��λ����
 company=dic['company']['name']  #��˾����
 salary=dic['salary']   #нˮ
 city=dic['city']['display']  #����
 jobtype = dic['jobType']['display']  #������ҵ
 eduLevel=dic['eduLevel']['name']   #ѧ��Ҫ��
 workingExp=dic['workingExp']['name']  #��������
 print(jobName,company,salary,city,jobtype,eduLevel,workingExp)
 writer.writerow([jobName,company,salary,city,jobtype,eduLevel,workingExp])
param={    'start':0,
 'pageSize':60,
 'cityId':489,
 'workExperience':-1,
 'education':-1,
 'companyType': -1,
 'employmentType': -1,
 'jobWelfareTag': -1,
 'kw': 'BI����ʦ',  #�����ؼ��ʣ����Ը�������Ҫ��ȡ�ĸ�λ��Ϣ���и���
 'kt': 3,
 'lastUrlQuery': {"p":1,"pageSize":"60","jl":"681","kw":"python","kt":"3"}
 }#��������
pages=range(1,31)#��ȡ1-30ҳ����
out_f = open('test.csv', 'w', newline='')
writer = csv.writer(out_f)
writer.writerow(['jobName','company','salary','city','jobtype','eduLevel','workingExp'])
for p in pages:  #�Զ���ҳ
 param['start']=(p-1)*60
 param['lastUrlQuery']['p']=p
 url = 'https://fe-api.zhaopin.com/c/i/sou?' + urlencode(param)
 GetData(url,writer)
 time.sleep(3)#�������3�룬��ֹIP����
 print(p)
out_f.close() 