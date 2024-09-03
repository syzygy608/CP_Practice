import requests
from bs4 import BeautifulSoup
from collections import defaultdict

# Step 1: Web scraping
url = "https://icpc.global/regionals/finder/Taiwan-Online-2025/teams"
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

# Step 2: Processing the data
teams = soup.find_all('tr', class_='MuiTableRow-root')

print(teams)

school_teams = defaultdict(list)

for team in teams:
    columns = team.find_all('td')
    if len(columns) >= 3:
        team_name = columns[1].text.strip()
        school = columns[0].text.strip()
        school_teams[school].append(team_name)

# Step 3: Analyzing the data
num_schools = len(school_teams)
print(f"Number of schools: {num_schools}")

print("\nTeams by school:")
for school, teams in sorted(school_teams.items()):
    print(f"\n{school}:")
    for team in sorted(teams):
        print(f"  - {team}")