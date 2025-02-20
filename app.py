from flask import Flask, jsonify
import requests

app = Flask(__name__)

def get_leetcode_daily():
    url = "https://leetcode.com/graphql"
    query = {
        "query": """
        query questionOfToday {
          activeDailyCodingChallengeQuestion {
            date
            question {
              title
              titleSlug
            }
          }
        }
        """
    }

    try:
        response = requests.post(url, json=query)
        response.raise_for_status()
        data = response.json()
        question_data = data.get("data", {}).get("activeDailyCodingChallengeQuestion")
        if not question_data:
            return {"error": "Failed to fetch the problem. Missing data."}

        return {
            "date": question_data["date"],
            "title": question_data["question"]["title"],
            "link": f"https://leetcode.com/problems/{question_data['question']['titleSlug']}/"
        }

    except (requests.exceptions.RequestException, KeyError, ValueError) as e:
        return {"error": f"Failed to fetch the problem. {str(e)}"}

@app.route('/daily_problem', methods=['GET'])
def daily_problem():
    return jsonify(get_leetcode_daily())

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
