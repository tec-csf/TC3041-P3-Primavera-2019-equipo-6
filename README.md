# TC3041-P3-Primavera-2019

Antony Adrian Morales

Alberto Pascal

[![Awesome](https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg)](https://github.com/wasabeef/awesome-android-ui)

# Endpoints
Ruta Desarrollo: http://127.0.0.1:3500/

## Cantidad máxima de relaciones en un nodo (GET) ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
    /peticion1

#### Respuesta esperada
    {
        "keys": [
            "max(Max_relations)"
        ],
        "length": 1,
        "_fields": [
            {
                "low": 3450,
                "high": 0
            }
        ],
        "_fieldLookup": {
            "max(Max_relations)": 0
        }
    }

## Nodos aquellos nodos que tienen menos de 200 relaciones.  (GET) ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
    /peticion2

#### Respuesta esperada
    [
        {
            "keys": [
                "Name",
                "connections"
            ],
            "length": 2,
            "_fields": [
                "Node192",
                {
                    "low": 5,
                    "high": 0
                }
            ],
            "_fieldLookup": {
                "Name": 0,
                "connections": 1
            }
        },
        {
            "keys": [
                "Name",
                "connections"
            ],
            "length": 2,
            "_fields": [
                "Node160",
                {
                    "low": 1,
                    "high": 0
                }
            ],
            "_fieldLookup": {
                "Name": 0,
                "connections": 1
            }
        },
    ]

## Nodo más nuevo/lejano al que se puede conectar el primer nodo  (GET) ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
    /peticion3

#### Respuesta esperada
    {
        "keys": [
            "Name",
            "max_id"
        ],
        "length": 2,
        "_fields": [
            "Node1",
            "95"
        ],
        "_fieldLookup": {
            "Name": 0,
            "max_id": 1
        }
    }

Orientaciones para la **Práctica 3. Graph databases**
# Contribuir
## Base de datos (Neo4j)

### Requisitos previos
- Docker instalado

### Correr Neo4j en container
`sudo docker run --name=neo4j -m=8g --publish=7474:7474 --publish=7687:7687 --volume=$HOME/neo4j/data:/data --env=NEO4J_AUTH=none neo4j`

### Importar Dataset
- Copiar .csv en docker: 
    - `sudo docker cp snap_nodes.csv neo4j:/var/lib/neo4j/import/`
    - `sudo docker cp soc-Slashdot0902.csv neo4j:/var/lib/neo4j/import/`

### Entrar a la base de datos
1. Entrar a: [http://localhost:7474](http://localhost:7474)
2. Importar grafo de nodos: `USING PERIODIC COMMIT LOAD CSV WITH HEADERS FROM "file:/snap_nodes.csv" AS row CREATE (:Nodes {Name: row.NodeName, id: row.Node_id});`
3. Importar las relaciones: `USING PERIODIC COMMIT 150 LOAD CSV WITH HEADERS FROM "file:/soc-Slashdot0902.csv" AS ROW MATCH (a:Nodes {id: ROW.FromNodeId}) MATCH (b:Nodes {id: ROW.ToNodeId}) CREATE (a)-[c:Connects_To]->(b) return c`

## Guía de estilos
### Mensajes en los Commits de Git

- Utilizar oraciones en presente ("Botón añadido" no "Se añadio botón")
- Comenzar el commit con mayúsculas
- Cuando solo se cambia documentacion añadir `[ci skip]` en el título del commit
- Considerar comenzar el commit con un emoji
    - :rocket: `:rocket:` cuando se lanza una nueva versión
    - :sparkles: `:sparkles:` cuando se añade nuevo código
    - :art: `:art:` mejora en el formato/estructura del código
    - :racehorse: `:racehorse:` mejora en el performance del código
    - :book: `:book:` cuando se escribe documentación
    - :bug: `:bug:` cuando se corrige un bug
    - :fire: `:fire:` cuando se eliminó código o archivos

## Notas

# Changelog
No hay cambios de ruptura

# Ayuda
antony999k@hotmail.com