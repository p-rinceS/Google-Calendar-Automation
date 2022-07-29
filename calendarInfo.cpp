
from pprint import pprint

# OAuth 2.0 Setup
from apiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow

# some permissions to take from the user.
scopes = ["https://www.googleapis.com/auth/calendar"]

#Client_secret.json is found in console.developers.google.com credentials for oAuth2.0
#unfortunately it's a secret so I cannot share it :/
flow = InstalledAppFlow.from_client_secrets_file("client_secret.json", scopes = scopes)


# required for first time run & authorization.  
# credentials = flow.run_console()

import pickle

#saving the token in a pickle file, not be continously asked for authorization code.
# pickle.dump(credentials, open("token.pkl", "wb"))

credentials = pickle.load(open("token.pkl", "rb"))



service = build("calendar", "v3", credentials = credentials)


# Get my calendars 
result = service.calendarList().list().execute()


# Get calendar events

# My Primary Calendar is V #1
cal_id = result['items'][1]['id']

getEvent = service.events().list(calendarId = cal_id).execute()
pprint(getEvent)


