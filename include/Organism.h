#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <vector>

struct Organism {
    // Genotype
    std::vector<std::string> genotype;
    int length;

    // Characteristics
    struct Size {
        float length;
        float weight;
    };

    struct Shape {
        float elongation;
        float width;
        float height;
    };

    struct Coloration {
        float hue;
        float brightness;
        float patternComplexity;
        float colorContrast;
    };

    struct Locomotion {
        float swimmingSpeed;
        float agility;
        float endurance;
    };

    struct FeedingMethod {
        float filterFeedingEfficiency;
        float predationSuccessRate;
        float herbivorySelectivity;
    };

    struct DigestiveSystem {
        float efficiency;
        float toleranceToDifferentFoodTypes;
        float specializedEnzymes;
    };

    struct Reproduction {
        float reproductiveStrategy;
        float matingBehaviors;
        float courtshipRituals;
    };

    struct Metabolism {
        float energyEfficiency;
        float metabolicRate;
        float thermoregulation;
    };

    struct Resilience {
        float resistanceToDisease;
        float abilityToRecoverFromInjuries;
        float stressTolerance;
    };

    struct SensoryPerception {
        float visualAcuity;
        float auditorySensitivity;
        float olfactoryDetection;
        float tactilePerception;
    };

    struct EnvironmentalAdaptation {
        float temperatureTolerance;
        float humidityTolerance;
        float habitatPreference;
        float altitudeAdaptation;
    };

    struct DefenseMechanisms {
        float camouflageEffectiveness;
        float toxicityLevel;
        float physicalDefenses;
        float warningSignals;
    };

    struct SocialBehavior {
        float solitaryVsGroupBehavior;
        float dominanceHierarchy;
        float cooperationLevel;
    };

    struct LifeSpan {
        float averageLifeSpan;
        float maximumLifeSpan;
    };

    struct ReproductiveInvestment {
        float numberOfOffspring;
        float parentalCareDuration;
        float parentalCareIntensity;
    };

    struct Communication {
        float vocalizations;
        float visualSignals;
        float chemicalSignals;
    };

    struct GrowthRate {
        float earlyGrowthRate;
        float lateGrowthRate;
    };

    struct AgingProcess {
        float rateOfSenescence;
        float ageRelatedDiseases;
    };

    struct Adaptability {
        float abilityToLearn;
        float behavioralFlexibility;
        float adaptabilityToChangingEnvironments;
    };

    struct EnergyStorage {
        float fatReserves;
        float glycogenStorage;
    };

    struct HabitatSpecialization {
        float habitatBreadth;
        float habitatDepth;
    };

    struct ImmuneSystem {
        float resistanceToPathogens;
        float immuneResponseEfficiency;
        float immuneMemory;
    };

    struct ForagingEfficiency {
        float searchTime;
        float energyAcquisitionRate;
        float preyCaptureSuccess;
    };

    struct BehavioralPlasticity {
        float adaptabilityToChangingConditions;
        float responseToEnvironmentalCues;
    };

    struct EnvironmentalSensitivity {
        float toleranceToPollutants;
        float sensitivityToTemperatureChanges;
        float responseToHabitatDegradation;
    };

    struct Longevity {
        float averageLongevity;
        float lateLifeDecline;
    };

    struct TerritorySize {
        float territoryArea;
        float territorialDefenseIntensity;
    };

    struct SocialStructure {
        float hierarchical;
        float egalitarian;
        float cooperativeBreeding;
    };

    struct CognitiveAbilities {
        float problemSolvingSkills;
        float memoryCapacity;
        float learningSpeed;
    };

    struct MatingSuccess {
        float matingRate;
        float mateChoiceSuccess;
    };

    // Phenotype
    struct Phenotype {
        Size size;
        Shape shape;
        Coloration coloration;
        Locomotion locomotion;
        FeedingMethod feedingMethod;
        DigestiveSystem digestiveSystem;
        Reproduction reproduction;
        Metabolism metabolism;
        Resilience resilience;
        SensoryPerception sensoryPerception;
        EnvironmentalAdaptation environmentalAdaptation;
        DefenseMechanisms defenseMechanisms;
        SocialBehavior socialBehavior;
        LifeSpan lifeSpan;
        ReproductiveInvestment reproductiveInvestment;
        Communication communication;
        GrowthRate growthRate;
        AgingProcess agingProcess;
        Adaptability adaptability;
        EnergyStorage energyStorage;
        HabitatSpecialization habitatSpecialization;
        ImmuneSystem immuneSystem;
        ForagingEfficiency foragingEfficiency;
        BehavioralPlasticity behavioralPlasticity;
        EnvironmentalSensitivity environmentalSensitivity;
        Longevity longevity;
        TerritorySize territorySize;
        SocialStructure socialStructure;
        CognitiveAbilities cognitiveAbilities;
        MatingSuccess matingSuccess;

        // Constructor
        Phenotype(const Size& size, const Shape& shape, const Coloration& coloration,
            const Locomotion& locomotion, const FeedingMethod& feedingMethod, const DigestiveSystem& digestiveSystem,
            const Reproduction& reproduction, const Metabolism& metabolism, const Resilience& resilience,
            const SensoryPerception& sensoryPerception, const EnvironmentalAdaptation& environmentalAdaptation,
            const DefenseMechanisms& defenseMechanisms, const SocialBehavior& socialBehavior,
            const LifeSpan& lifeSpan, const ReproductiveInvestment& reproductiveInvestment,
            const Communication& communication, const GrowthRate& growthRate, const AgingProcess& agingProcess,
            const Adaptability& adaptability, const EnergyStorage& energyStorage,
            const HabitatSpecialization& habitatSpecialization, const ImmuneSystem& immuneSystem,
            const ForagingEfficiency& foragingEfficiency, const BehavioralPlasticity& behavioralPlasticity,
            const EnvironmentalSensitivity& environmentalSensitivity, const Longevity& longevity,
            const TerritorySize& territorySize, const SocialStructure& socialStructure,
            const CognitiveAbilities& cognitiveAbilities, const MatingSuccess& matingSuccess)
            : size(size), shape(shape), coloration(coloration),
            locomotion(locomotion), feedingMethod(feedingMethod), digestiveSystem(digestiveSystem),
            reproduction(reproduction), metabolism(metabolism), resilience(resilience),
            sensoryPerception(sensoryPerception), environmentalAdaptation(environmentalAdaptation),
            defenseMechanisms(defenseMechanisms), socialBehavior(socialBehavior),
            lifeSpan(lifeSpan), reproductiveInvestment(reproductiveInvestment),
            communication(communication), growthRate(growthRate), agingProcess(agingProcess),
            adaptability(adaptability), energyStorage(energyStorage),
            habitatSpecialization(habitatSpecialization), immuneSystem(immuneSystem),
            foragingEfficiency(foragingEfficiency), behavioralPlasticity(behavioralPlasticity),
            environmentalSensitivity(environmentalSensitivity), longevity(longevity),
            territorySize(territorySize), socialStructure(socialStructure),
            cognitiveAbilities(cognitiveAbilities), matingSuccess(matingSuccess) {}
    } phenotype;

    // Energy
    float energyLevel;
    float consumptionRate;
    float minEnergyThreshold;
    float maxEnergyThreshold;

    // Position
    float x;
    float y;

    // Reproduction
    float reproductionThreshold;
    float reproductionRate;

    // Movement
    float speed;
    float direction;

    // Constructor
    Organism(const std::vector<std::string>& _genotype, float _size, float _shape, float _coloration,
        float _consumptionRate, float _minEnergyThreshold, float _maxEnergyThreshold,
        float _reproductionThreshold, float _reproductionRate, float _speed, float _direction);

    // Method to update the phenotype based on stock data
    void updatePhenotype();

    // Method to consume energy
    void consumeEnergy();

    // Method to reproduce
    Organism reproduce();

    // Method to move
    void move();

    // Method to interact with the environment and other organisms
    void interact();

    // Add more methods as needed
};

#endif
