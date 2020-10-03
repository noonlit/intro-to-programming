# bfs
from collections import deque

def personIsProgrammer(name):
	return name[-1] == 'm' # let's say

def findProgrammerBFS(graph, start):
	queue    = deque()
	queue   += graph[start]
	searched = []

	while queue:
		person = queue.popleft()

		if person in searched:
			continue

		if personIsProgrammer(person):
			print(person)
			return True
		else:
			queue += graph[person]

	return False

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

findProgrammerBFS(graph, 'you')