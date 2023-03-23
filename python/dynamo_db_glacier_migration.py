import boto3
from botocore.exceptions import ClientError
import os
from dotenv import load_dotenv

load_dotenv()
AWS_ACCESS_KEY_ID=os.environ.get('AWS_ACCESS_KEY_ID')
AWS_SECRET_ACCESS_KEY=os.environ.get('AWS_SECRET_ACCESS_KEY')
s3_client = boto3.client('s3',aws_access_key_id=AWS_ACCESS_KEY_ID,aws_secret_access_key=AWS_SECRET_ACCESS_KEY)
# To get list of buckets present in AWS using S3 client
def get_buckets_client():
    # User can pass customized access key, secret_key and token as well
    try:
       response = s3_client.list_buckets()
       buckets =[]
       for bucket in response['Buckets']:
            buckets += {bucket["Name"]}
    except ClientError:
        print("Couldn't get buckets.")
        raise
    else:
         return buckets
   
buckets_list=get_buckets_client()

print(buckets_list)
buckets_removed={'again-test'}
print(buckets_removed)

for x in buckets_list:
    print(x,end =": ")
    if x not in buckets_removed:
        print("Rule will implemented")
        try:
            response = s3_client.put_bucket_lifecycle_configuration(
                Bucket= x,
                LifecycleConfiguration= {
                    'Rules':[
                        {
                            'Filter': {
                                'Prefix': ''
                            },
                            'ID': 'New rule',
                            'Status': 'Enabled',
                            'Transitions': [
                                {'Days': 1,'StorageClass': 'GLACIER',},
                                {'Days': 91,'StorageClass': 'DEEP_ARCHIVE'}
                            ]
                        }
                    ]
                }
            ) 
            print(response['ResponseMetadata']['HTTPStatusCode'])
        except:
            print("Error occured")
            raise 
    else:
        print("No rule  will implemented")