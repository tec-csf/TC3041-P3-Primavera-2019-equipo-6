# TC3041-P3-Primavera-2019

Antony Adrian Morales

Alberto Pascal

[![Awesome](https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg)](https://github.com/wasabeef/awesome-android-ui)

Orientaciones para la **Práctica 3. Graph databases**
# Contribuir
## Base de datos (Neo4j)

### Requisitos previos
- Docker instalado

### Correr Neo4j en container
`docker run --name=neo4j -m=4g --publish=7474:7474 --publish=7687:7687 --volume=$HOME/neo4j/data:/data --env=NEO4J_AUTH=none neo4j`

### Importar Dataset
- Copiar .csv en docker: `docker cp out.csv neo4j:/var/lib/neo4j/import/`
USING PERIODIC COMMIT LOAD CSV WITH HEADERS FROM "file:/nodes.csv" AS row CREATE (:Node {nodeID: row.nodeId});
- Neo4j Querie: `LOAD CSV FROM "file:///out.csv" AS line RETURN count(*);`

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