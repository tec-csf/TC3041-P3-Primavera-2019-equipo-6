//controllers/practica.controller.js
'use strict';
// DB  =========================================================
var neo4j = require('neo4j-driver').v1;
const driver = neo4j.driver('bolt://localhost');
const session = driver.session();

//3 Consultas de Neo 4j para el dataset 6 SlashDot

//Cantidad máxima de relaciones en un nodo
exports.peticion1 = (req, res, next) => {
    session
    .run('match(n:Nodes)-[r:Connects_To]->(b:Nodes) with count(r) as Max_relations return max(Max_relations)')
    .then(function(result){
      res.status(200).json(result.records[0]);
      session.close();
    })
    .catch(function(result){
        let e = new Error(err);
        e.name = "internal";
        return next(e);
    })
  }

//Todos aquellos nodos que tienen menos de 200 relaciones.
exports.peticion2 = (req, res, next) => {
    session
    .run('match(n:Nodes)-[r:Connects_To]->(b:Nodes) with b.Name as Name, count(r) as connections where connections < 200 return Name, connections')
    .then(function(result){
      res.status(200).json(result.records);
      session.close();
    })
    .catch(function(result){
        let e = new Error(err);
        e.name = "internal";
        return next(e);
    })
  }

//El nodo más nuevo/lejano al que se puede conectar el primer nodo
exports.peticion3 = (req, res, next) => {
    session
    .run('match(n:Nodes)-[r:Connects_To]->(b:Nodes) with n.Name as Name, max(b.id) as max_id  where Name = "Node1" return Name, max_id')
    .then(function(result){
      res.status(200).json(result.records[0]);
      session.close();
    })
    .catch(function(result){
        let e = new Error(err);
        e.name = "internal";
        return next(e);
    })
  }