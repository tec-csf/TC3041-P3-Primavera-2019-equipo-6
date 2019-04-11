#Iniciar un contenedor de docker con neo4j
sudo docker run --name=neo4j -m=8g --publish=7474:7474 --publish=7687:7687 --volume=$HOME/neo4j/data:/data --env=NEO4J_AUTH=none neo4j

#copiar el archivo de Alumnos.csv a docker:
sudo docker cp snap_nodes.csv neo4j:/var/lib/neo4j/import/


#Entrar a la base de datos:
http://localhost:7474.

#Importar el grafo de Nodos
USING PERIODIC COMMIT
LOAD CSV WITH HEADERS FROM "file:/snap_nodes.csv" AS row
CREATE (:Nodes {Name: row.NodeName, id: row.Node_id});

#Copiar los archivos de relaciones a docker:
sudo docker cp soc-Slashdot0902.csv neo4j:/var/lib/neo4j/import/

#Importar las relaciones:

#Relaciones
USING PERIODIC COMMIT 150
LOAD CSV WITH HEADERS FROM "file:/soc-Slashdot.csv" AS ROW
MATCH (a:Nodes {id: ROW.FromNodeId})
MATCH (b:Nodes {id: ROW.ToNodeId})
CREATE (a)-[c:Connects_To]->(b)
return c

