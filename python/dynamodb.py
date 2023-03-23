import boto3
from boto3.dynamodb.conditions import Key
dynamodb = boto3.resource('dynamodb', region_name='us-west-2')

table = dynamodb.Table('mithoo-prod-user-org-v1')
table_org = dynamodb.Table("mithoo-prod-organization-v1")
org_detail={}
org={}
def printing(user):
    for x in user:
        user_id=str(x)
        response = table.query(KeyConditionExpression=Key('user_id').eq(user_id))
        org_id=response['Items'][0]['org_id'][4:]
        org_detail_query= table_org.query(KeyConditionExpression=Key('org_id').eq(org_id))
        org_req_detail = {
            "created_ts": org_detail_query['Items'][0]["created_ts"],
            "id": org_detail_query['Items'][0]["org_id"],
            "email": org_detail_query['Items'][0]["email_domain"],
            "active": org_detail_query['Items'][0]["is_active"],
            "time_zone": org_detail_query['Items'][0]["default_tz"],
            "name": org_detail_query['Items'][0]["name"]
        }
        org_name=org_detail_query['Items'][0]["name"]
        if org_name not in org.keys():
            org[org_name]=[]
            org_detail[org_name]={}
        org[org_name].append(user_id)
        org_detail[org_name]=org_req_detail
    for x in org:
        print(x,org[x])
    return [org,org_detail]