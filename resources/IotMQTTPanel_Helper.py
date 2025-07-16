import json
import argparse

VERSION="1.0.0"

parser = argparse.ArgumentParser(
    prog='IoTMQTTPanel_Helper',
    description='Pretty print JSON converter and ClientID injection')
parser.add_argument("JSONin", help="Input JSON File")
parser.add_argument("-o", "--out", help="Output JSON to file", required=False)
parser.add_argument("-b", "--broker", help="MQTT broker", required=False)
parser.add_argument("-c", "--clientid", help="MQTT Client ID to inject", required=False)
parser.add_argument("-u", "--username", help="MQTT Username credentials", required=False)
parser.add_argument("-p", "--password", help="MQTT Password credentials", required=False)
parser.add_argument('--version', action='version', version='%(prog)s v'+VERSION)

args = parser.parse_args()


print("\nIoTMQTTPanel_Helper")
with open(args.JSONin, "r") as JSONfile_in:
    print("JSON in: ", args.JSONin)
    jsonin = JSONfile_in.read()
    python_object = json.loads(jsonin)
    jsonout = json.dumps(python_object, indent=2)
    if args.clientid != None:
        #--clientid option set, inject new clientid
        count = jsonout.count("mySTM32_772")
        jsonout2 = jsonout.replace("mySTM32_772", args.clientid)
        print("Inserted ClientID \"" + args.clientid +"\" " + str(count) + " times")
    else:
        #--clientid not set
        jsonout2 = jsonout
    jsonout=jsonout2
        
    if args.username != None:
        #--username option set, inject new username
        count = jsonout.count('"username": ""')
        jsonout2 = jsonout.replace('"username": ""', f'"username": "{args.username}"')
        print(f"Inserted Username \"{args.username}\" {count} times")
    
    jsonout=jsonout2
        
    if args.password != None:
        #--password option set, inject new password
        count = jsonout.count('"password": ""')
        jsonout2 = jsonout.replace('"password": ""', f'"password": "{args.password}"')
        print(f"Inserted Password \"{args.password}\" {count} times")
        
    jsonout=jsonout2
    if args.broker != None:
        #--broker option set
        count = jsonout.count("broker.hivemq.com")
        jsonout2 = jsonout.replace("broker.hivemq.com", args.broker)
        print("Inserted Broker \"" + args.broker +"\" " + str(count) + " times")

    if args.out != None:
        # --out selected, save output to specified file
        with open(args.out, "w") as JSONfile_out:
            print("Saving output to:",args.out)
            JSONfile_out.write(jsonout2)
            JSONfile_out.close()
            print("Done")
    else:
        #no output file, print to screen
        print("\n"+jsonout2)
