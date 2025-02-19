from flask import Flask, jsonify
import requests

app = Flask(__name__)

def get_leetcode_daily():
    url = "https://leetcode.com/graphql"
    headers = {
        "Content-Type": "application/json"
    }
    query = {
        "query": """
        query questionOfToday {
          activeDailyCodingChallengeQuestion {
            date
            link
            question {
              title
            }
          }
        }
        """
    }
    
    response = requests.post(url, json=query, headers=headers)
    
    if response.status_code == 200:
        data = response.json()
        question = data["data"]["activeDailyCodingChallengeQuestion"]
        date = question["date"]
        problem_title = question["question"]["title"]
        problem_link = f"https://leetcode.com{question['link']}"
        
        return f"Today's ({date}) LeetCode problem: {problem_title}\n{problem_link}"
    else:
        return "Could not fetch today's problem. API error."
print(get_leetcode_daily())

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True) 
