#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <vector>

struct Organism {

    // Phenotype
    enum Phenotype {

        // SHAPE {
        // ELONGATION,
        WIDTH,
        LENGTH,

        // COLORATION {
        HUE,
        SATURATION,
        VALUE,
        ALPHA,
        // PATTERNCOMPLEXITY,

        // LOCOMOTION {
        SWIMMINGSPEED,
        // AGILITY,
        // ENDURANCE,
        // WANT VARIABLE SPEED AS WELL

        // FEEDINGMETHOD {
        // FILTERFEEDINGEFFICIENCY,
        // PREDATIONEFFICIENCY,
        // HERBIVORYSELECTIVITY,

        // DIGESTIVESYSTEM {
        EATING_EFFICIENCY,
        EATING_SPEED,
        // TOLERANCETODIFFERENTFOODTYPES,
        // SPECIALIZEDENZYMES,

        // REPRODUCTION {
        // REPRODUCTIVESTRATEGY,
        // MATINGBEHAVIORS,
        // COURTSHIPRITUALS,

        // METABOLISM {
        ENERGY_EFFICIENCY,
        // METABOLICRATE,
        // THERMOREGULATION,

        // RESILIENCE {
        RESISTANCE_TO_TOXINS,
        // ABILITYTORECOVERFROMINJURIES,
        // STRESSTOLERANCE,

        // SENSORYPERCEPTION {
        // VISUALACUITY,           //OBSTACLES, LIGHT, NUTRIENTS, TOXINS
        // AUDITORYSENSITIVITY,
        // OLFACTORYDETECTION,     //NUTRIENTS, TOXINS
        // TACTILEPERCEPTION,      //TOXINS, CURRENT
        

        // ENVIRONMENTALADAPTATION {
        //TEMPERATURETOLERANCE,
        //HUMIDITYTOLERANCE,
        LIGHT_ATTRACTION,
        OBSTACLE_ATTRACTION,
        NUTRIENT_ATTRACTION,
        TOXIC_ATTRACTION,
        CURRENT_ATTRACTION,
        SAME_SPECIES_ATTRACTION,
        OTHER_SPECIES_ATTRACTION,
        //ALTITUDEADAPTATION,

        // DEFENSEMECHANISMS {
        // CAMOUFLAGEEFFECTIVENESS,
        // TOXICITYLEVEL,
        // PHYSICALDEFENSES,
        // WARNINGSIGNALS,

        // SOCIALBEHAVIOR {
        // SOLITARYVSGROUPBEHAVIOR,
        // DOMINANCEHIERARCHY,
        COMMUNICATION,

        // LIFESPAN {
        LIFESPAN,
        // MAXIMUMLIFESPAN,

        // REPRODUCTIVEINVESTMENT {
        NUMBER_OF_OFFSPRING,
        // PARENTALCAREDURATION,
        // PARENTALCAREINTENSITY,

        // COMMUNICATION {
        // VOCALIZATIONS,
        // VISUALSIGNALS,
        // CHEMICALSIGNALS,

        // GROWTHRATE {
        GROWTH_RATE,
        // LATEGROWTHRATE,

        // AGINGPROCESS {
        // RATEOFSENESCENCE,
        // AGERELATEDDISEASES,

        // ADAPTABILITY {
        // ABILITYTOLEARN,
        // BEHAVIORALFLEXIBILITY,
        // ADAPTABILITYTOCHANGINGENVIRONMENTS,

        // ENERGYSTORAGE {
        // FATRESERVES,
        // GLYCOGENSTORAGE,

        // HABITATSPECIALIZATION {
        // HABITATBREADTH,
        // HABITATDEPTH,

        // IMMUNESYSTEM {
        // RESISTANCETOPATHOGENS,
        // IMMUNERESPONSEEFFICIENCY,
        // IMMUNEMEMORY,

        // FORAGINGEFFICIENCY {
        // SEARCHTIME,
        // ENERGYACQUISITIONRATE,
        // PREYCAPTURESUCCESS,

        // BEHAVIORALPLASTICITY {
        // ADAPTABILITYTOCHANGINGCONDITIONS,
        // RESPONSETOENVIRONMENTALCUES,

        // ENVIRONMENTALSENSITIVITY {
        // TOLERANCETOPOLLUTANTS,
        // SENSITIVITYTOTEMPERATURECHANGES,
        // RESPONSETOHABITATDEGRADATION,

        // LONGEVITY {
        // AVERAGELONGEVITY,
        // LATELIFEDECLINE,

        // TERRITORYSIZE {
        // TERRITORYAREA,
        // TERRITORIALDEFENSEINTENSITY,

        // SOCIAL {
        // HIERARCHICAL,
        // EGALITARIAN,
        // COOPERATIVEBREEDING,

        // COGNITIVEABILITIES {
        // PROBLEMSOLVINGSKILLS,
        // MEMORYCAPACITY,
        // LEARNINGSPEED,

        // MATINGSUCCESS {
        // MATINGRATE,
        // MATECHOICESUCCESS,

        // ENERGY {
        // CONSUMPTIONRATEMULTIPLIER,
        MAX_ENERGY,

        // META 
        // PRIORITY,
        GENOTYPE_SIZE
    };

    // Genotype
    const static int genotypeSize = GENOTYPE_SIZE-1;
    std::vector<std::string> genotype;

    // Energy
    float energyLevel;

    // Position
    float x;
    float y;

    // Reproduction
    // float reproductionThreshold;
    // float reproductionRate;

    // Movement
    float speed;
    float direction;

    // float priority;

    // Constructor
    Organism();
        //, float x = 0, float y = 0, float _speed = 0.0, int _direction = 0);

    // Method to update the phenotype based on stock data
    // void updatePhenotype();
    // 
    // // Method to reproduce
    // void reproduce();
    // 
    // // Method to move
    // void move();
    // 
    // // Method to interact with the environment and other organisms
    // void interact();

    // Add more methods as needed
};

#endif
