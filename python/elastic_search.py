import requests
import boto3
import json
from requests_aws4auth import AWS4Auth
from dynamodb import printing
def get_awsauth(region, service):
    credentials = boto3.Session().get_credentials()
    awsauth = AWS4Auth(
        region=region,
        service=service,
        refreshable_credentials=credentials
    )
    return awsauth


endpoint = 'https://metrics.polly.elucidata.io/'
region = 'us-west-2'
service = 'es'
query_type="_search"
query={
    "query": { 
        "bool": { 
        "filter": [ 
            { "range": { "created_ts": { "gte": "2023-02-18" }}}
        ]
        }
    },
    "aggs" : {
        "whatever_you_like_here" : {
            "terms" : { "field" : "user.id", "size":10000 }
        }
    },
    "size" : 0
}
kwargs = {
    'url': endpoint + "blue-compute-cost-metrics/"+query_type,
    'method': "get",
    'auth': get_awsauth(region,service),
    'json': query,
    'timeout': 15
}
try:
    req = requests.request(**kwargs)
except Exception as err:
    print(err)

req_data={ 'data': json.loads(req.text)}
users_buckets=req_data['data']['aggregations']['whatever_you_like_here']['buckets']
users=set()
for x in users_buckets:
    users.add(x['key'])

result=printing(users)

for x in result[0]:
        print(x,result[0][x])

for x in result[1]:
        print(x,result[1][x])
# for x in result:
#     id=result[x]['id']
#     email=result[x]['email']
#     active=str(result[x]['active'])
#     time_zone=result[x]['time_zone']
#     name=result[x]['name']
#     created_ts=result[x]['created_ts']
#     if active=='True':
#         active='true'
#     if active=='False':
#         active=='false'
#     scr="ctx._source.organization['created_ts']= '"+str(created_ts)+"'; ctx._source.organization['id']= "+id+"; ctx._source.organization['email']= '"+email+"'; ctx._source.organization['active']= "+active+"; ctx._source.organization['time_zone']= '"+time_zone+"'; ctx._source.organization['name']= '"+name+"'"
#     print(scr)
#     query_2={
#         "query": {
#             "bool": {
#             "filter": [ 
#                 { "term":  { "user.id": x }},
#                 { "range": { "created_ts": { "gte": "2023-02-18" }}}
#             ]
#             }
#         }, 
#         "script": {
#             "source": scr,
#             "lang": "painless"
#         },
#         "size": 10000
#     }
#     kwargs_2 = {
#         'url': endpoint + "blue-compute-cost-metrics/_update_by_query",
#         'method': "post",
#         'auth': get_awsauth(region,service),
#         'json': query_2,
#         'timeout': 15
#     }

#     try:
#         req = requests.request(**kwargs_2)
#     except Exception as err:
#         print(err)

#     print(req.text)