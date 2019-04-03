//controllers/practica.controller.js
'use strict';
// DB  =========================================================
var neo4j = require('neo4j-driver').v1;
const driver = neo4j.driver('bolt://localhost');
const session = driver.session();

//3 Consultas de Neo 4j para el dataset 6 SlashDot

//
exports.peticion1 = (req, res, next) => {
    session
    .run('MATCH (n) RETURN n ')
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

  //
exports.peticion2 = (req, res, next) => {
    session
    .run('MATCH (n) RETURN n ')
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

  //
exports.peticion3 = (req, res, next) => {
    session
    .run('MATCH (n) RETURN n ')
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