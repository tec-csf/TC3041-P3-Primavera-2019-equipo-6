#Cantidad máxima de relaciones en un nodo

match(n:Nodes)-[r:Connects_To]->(b:Nodes) with count(r) as Max_relations return max(Max_relations)

#Todos aquellos nodos que tienen menos de 200 relaciones. 

match(n:Nodes)-[r:Connects_To]->(b:Nodes) with b.Name as Name, count(r) as connections where connections < 200 return Name, connections

#el nodo más nuevo/lejano al que se puede conectar el primer nodo:

match(n:Nodes)-[r:Connects_To]->(b:Nodes) with n.Name as Name, max(b.id) as max_id  where Name = 'Node1' return Name, max_id;
