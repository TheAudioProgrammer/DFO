//
//  Main.h
//  dfoBasic
//
//  Created by Joshua Hodge on 10/17/17.
//  Copyright © 2017 Joshua Hodge. All rights reserved.
//

#include <vector>
#include <random>

#ifndef Main_h
#define Main_h

std::default_random_engine generator;
std::uniform_real_distribution <float> randFloat (0.0, 1.0);

//fly population size
int popSize = 100;

//each fly contains 5 values
int solutionSize = 5;

//use disturbance threshold to disturb flies
float disturbanceThresh = 0.5f;

//target solution
std::vector <float> targetSolution {-1.0, -1.0, -1.0, -0.8, 1.0};

//empty vector for the fly population

std::vector <float> fly; //holds values for each fly
std::vector <std::vector <float>> population; //vector to hold whole population

std::vector <float> fitness;

//set upper and lower bounds of data space
float lowerBounds = -1.0f;
float upperBounds = 1.0f;

//iterations/generations
int totalIterations = 100;

int fittestInSwarm;


#endif /* Main_h */
