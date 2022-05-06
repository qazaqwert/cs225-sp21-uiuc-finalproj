import networkx as nx
import matplotlib.pyplot as plt

edges = []
with open('edges.txt', 'r') as f:
	for l in f:
		data = l.split(", ")
		data[1] = data[1].rstrip()
		edges.append(data)

edges_list = [(edge[0], edge[1]) for edge in edges]

path = []
with open('path.txt', 'r') as f:
	for l in f:
		l = l.rstrip()
		path.append(l)

colors = ['red' for i in path]
path_nodes = {name:value for (name, value) in zip(path, colors)}

path_edges = []

for i in range(len(path) - 1):
	path_edges.append((path[i], path[i + 1]))
print(path_edges)


G = nx.DiGraph()
G.add_edges_from(edges_list)

edge_colors = []
for edge in G.edges():
	if (edge in path_edges):
		edge_colors.append('red')
	else:
		edge_colors.append('gray')

edge_widths = []
for edge in G.edges():
	if (edge in path_edges):
		edge_widths.append(1.5)
	else:
		edge_widths.append(0.5)


values = [path_nodes.get(nodes, 'yellow') for nodes in G.nodes()]
#edge_values = [path_edges_colors.get(edges, 0.8) for edges in G.edges()]

pos = nx.kamada_kawai_layout(G)
nx.draw_networkx_nodes(G, pos, node_size = 50, node_color = values)
nx.draw_networkx_edges(G, pos, edgelist = G.edges(), edge_color = edge_colors, width=edge_widths)
nx.draw_networkx_labels(G, pos, font_size = 6, font_color='black')

mng = plt.get_current_fig_manager()
mng.window.state('zoomed')
plt.show()

#nx.draw(G, with_labels = 1)
