from flask import Flask, jsonify
import requests

app = Flask(__name__)

def fetch_daily_problem():
    url = "https://leetcode.com/graphql"
    query = {
        "query": """
        query dailyCodingChallenge {
          activeDailyCodingChallengeQuestion {
            date
            question {
              title
              link
            }
          }
        }
        """
    }

    try:
        response = requests.post(url, json=query)
        response.raise_for_status()

        data = response.json()
        question = data["data"]["activeDailyCodingChallengeQuestion"]

        return {
            "date": question["date"],
            "title": question["question"]["title"],
            "link": f"https://leetcode.com{question['question']['link']}"
        }

    except (requests.exceptions.RequestException, KeyError, ValueError) as e:
        return {"error": f"Failed to fetch the problem. {str(e)}"}

@app.route("/daily-problem", methods=["GET"])
def daily_problem():
    result = fetch_daily_problem()
    return jsonify(result)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
    
