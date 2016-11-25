#pragma once
using namespace std;
#include <vector>
#include <map>
#include "Chromosome.hpp"

class SimpleGA
{
private:
	vector<Chromosome*>* population;
	vector<Chromosome*> offsprings;
	vector<Node*>* nodes;
	int dimension;
	int capacity;

	int samples;
	int generations;
	float mutationProbability;

	Chromosome* bestSolution;
public:
	SimpleGA(vector<Chromosome*>* p, vector<Node*>* n, int d, int c);
	void generatePopulation();
	void evaluatePopulation();
	void reproduceOffspring();
	void replacePopulation();
	void evaluateSolution();
	void stepGA();
	void filtration();
	void writeResult();
	void run();


	vector<Chromosome*> rouletteSelection();
	vector<Chromosome*> tournamentSelection(int n);
	void pmx(Chromosome* p1, Chromosome* p2);
	void swapGenes(int i, Chromosome* p1, Chromosome* p2, Chromosome* chromosome);
	void vrpCrossover(Chromosome* p1, Chromosome* p2);
	void scx(Chromosome* p1, Chromosome* p2);
	void ox(Chromosome* p1, Chromosome* p2);
	void fillNodes(int chromosome[], int parent[], int size, map<int, int>* existing);
	void pb(Chromosome* p1, Chromosome* p2);
	void ob(Chromosome* p1, Chromosome* p2);
	void cx(Chromosome* p1, Chromosome* p2);

	Chromosome* swapMutation(Chromosome* ch);
	Chromosome* inversionMutation(Chromosome* ch);
	Chromosome* insertionMutation(Chromosome* ch);

	void repair(Chromosome* chromosome, int ch[], int size);
	void naiveRepair(Chromosome* chromosome, int ch[], int size);
};
