#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <vector>

struct Organism {
    // Genotype
    std::vector<std::string> genotype;

    // Phenotype
    enum Phenotype {
        length,
        weight,

        // Shape {
        elongation,
        width,
        height,

        // Coloration {
        hue,
        saturation,
        value,
        patternComplexity,

        // Locomotion {
        swimmingSpeed,
        agility,
        endurance,

        // FeedingMethod {
        filterFeedingEfficiency,
        predationSuccessRate,
        herbivorySelectivity,

        // DigestiveSystem {
        efficiency,
        toleranceToDifferentFoodTypes,
        specializedEnzymes,

        // Reproduction {
        reproductiveStrategy,
        matingBehaviors,
        courtshipRituals,

        // Metabolism {
        energyEfficiency,
        metabolicRate,
        thermoregulation,

        // Resilience {
        resistanceToDisease,
        abilityToRecoverFromInjuries,
        stressTolerance,

        // SensoryPerception {
        visualAcuity,
        auditorySensitivity,
        olfactoryDetection,
        tactilePerception,

        // EnvironmentalAdaptation {
        temperatureTolerance,
        humidityTolerance,
        habitatPreference,
        altitudeAdaptation,

        // DefenseMechanisms {
        camouflageEffectiveness,
        toxicityLevel,
        physicalDefenses,
        warningSignals,

        // SocialBehavior {
        solitaryVsGroupBehavior,
        dominanceHierarchy,
        cooperationLevel,

        // LifeSpan {
        averageLifeSpan,
        maximumLifeSpan,

        // ReproductiveInvestment {
        numberOfOffspring,
        parentalCareDuration,
        parentalCareIntensity,

        // Communication {
        vocalizations,
        visualSignals,
        chemicalSignals,

        // GrowthRate {
        earlyGrowthRate,
        lateGrowthRate,

        // AgingProcess {
        rateOfSenescence,
        ageRelatedDiseases,

        // Adaptability {
        abilityToLearn,
        behavioralFlexibility,
        adaptabilityToChangingEnvironments,

        // EnergyStorage {
        fatReserves,
        glycogenStorage,

        // HabitatSpecialization {
        habitatBreadth,
        habitatDepth,

        // ImmuneSystem {
        resistanceToPathogens,
        immuneResponseEfficiency,
        immuneMemory,

        // ForagingEfficiency {
        searchTime,
        energyAcquisitionRate,
        preyCaptureSuccess,

        // BehavioralPlasticity {
        adaptabilityToChangingConditions,
        responseToEnvironmentalCues,

        // EnvironmentalSensitivity {
        toleranceToPollutants,
        sensitivityToTemperatureChanges,
        responseToHabitatDegradation,

        // Longevity {
        averageLongevity,
        lateLifeDecline,

        // TerritorySize {
        territoryArea,
        territorialDefenseIntensity,

        // Social {
        hierarchical,
        egalitarian,
        cooperativeBreeding,

        // CognitiveAbilities {
        problemSolvingSkills,
        memoryCapacity,
        learningSpeed,

        // MatingSuccess {
        matingRate,
        mateChoiceSuccess,

        // Energy {
        consumptionRateMultiplier,
        maxEnergy,
    };

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

    // Constructor
    Organism(const std::vector<std::string>& _genotype);
        //, float x = 0, float y = 0, float _speed = 0.0, int _direction = 0);

    // Method to update the phenotype based on stock data
    void updatePhenotype();

    // Method to consume energy
    void consumeEnergy();

    // Method to reproduce
    void reproduce();

    // Method to move
    void move();

    // Method to interact with the environment and other organisms
    void interact();

    // Add more methods as needed
};

#endif
