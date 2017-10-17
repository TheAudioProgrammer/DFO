//
//  main.cpp
//  dfoBasic
//
//  Created by Joshua Hodge on 10/17/17.
//  Copyright © 2017 Joshua Hodge. All rights reserved.
//

#include <iostream>
#include "Main.h"

int main (int argc, char* argv[])
{
    
    //make flies and give them a random position
    for (int i = 0; i < popSize; i++)
    {
        //create a new fly with 5 random values
        for (int j = 0; j < solutionSize; j++)
        {
            //randfloat produces random values between -1 and 1
            float randNum = lowerBounds+ randFloat(generator) * (upperBounds - lowerBounds);
            
            fly.push_back(randNum);
        }
        population.push_back(fly);
        fly.clear();
    }
    
    //generations and iterations
    for (int iterations = 0; iterations < totalIterations; iterations++)
    {
        fitness.clear();        //each iteration we must clear fitnesses and reload
        
        //fitness function
        for (int i = 0; i < population.size(); i++)
        {
            float temp = 0;
            
            for (int j = 0; j < targetSolution.size(); j++)
            {
                //euclidean distance square result of differences
                float fitness = pow (targetSolution[j] - population[i][j], 2);
                temp = fitness + temp;          //temp stores fitnesses until solution size
                
                if (j == targetSolution.size() - 1)
                {
                    temp = sqrt(temp);      //square root of sum
                }
            }
            //push distances into vector
            fitness.push_back(temp);
        }
        
        
        //find fly with best fitness (closest to ideal solution)
        auto result = std::min_element(std::begin(fitness), std::end(fitness));
        fittestInSwarm = (int)(result - fitness.begin());   //index of fittest in swarm
        
        for (int i = 0; i < fitness.size(); i++)
        {
            int leftFly;
            int rightFly;
            
            if (i == 0)
            {
                leftFly = (int)fitness.size() - 1;
            }
            else
            {
                //compare left and right fly and find more fit
                leftFly = i - 1;
            }
            
            //if last fly, right fly is first fly
            if (i == fitness.size() - 1)
            {
                rightFly = 0;
            }
            else
            {
                rightFly = i + 1;
            }
            
                //find fittest neighbor
                int bestNeighbor = 0;
            
                if (fitness[leftFly] < fitness[rightFly])
                {
                    bestNeighbor = leftFly;
                
                }
                else if (fitness[leftFly] > fitness[rightFly])
                {
                    bestNeighbor = rightFly;
                }
            
            //update function
            for (int j = 0; j < solutionSize; j++)
            {
                //random dice throw to sometimes redistribute fly
                float threshold = randFloat (generator);
                
                //if dt > r
                if (threshold < disturbanceThresh)
                {
                    //randomly scatter fly
                    float randNum = lowerBounds+ randFloat (generator) * (upperBounds - lowerBounds);
                    
                    population[i][j] = randNum;
                    
                }
                else
                {
                    //update position
                    population[i][j] = population[bestNeighbor][j] + randFloat (generator) * (population[fittestInSwarm][j] - population[bestNeighbor][j]);
                }
            }
        }
    }
    
    
//    //test
//    for (int i = 0; i < 1; i++)
//    {
//        for (int j = 0; j < solutionSize; j++)
//        {
//            std::cout << fittestInSwarm << " is the fittest fly with values " << population[fittestInSwarm][j] << std::endl;
//        }
//    }
    
    
    
    return 0;
}
