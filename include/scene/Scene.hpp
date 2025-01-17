/*
** EPITECH PROJECT, 2023
** Epitech-Raytracer
** File description:
** Scene
*/

#pragma once

#include "render/Ray.hpp"
#include "objects/Object.hpp"
#include "lights/LightPoint.hpp"
#include "lights/DirectionalLight.hpp"
#include "lights/BackgroundLight.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include "render/Camera.hpp"

class Scene {
    public:
        Scene() : _backgroundLight(BackgroundLight(WHITE)), _ambientLight(ALight(WHITE)) {};
        ~Scene() = default;

        // Setters
        void setMultithreadingEnabled(const bool &enabled);
        void setClusters(const std::vector<std::string> &clusters);
        void setPreRenderEnabled(const bool &enabled);
        void setContinuousRenderEnabled(const bool &enabled);
        void setOutputFile(const std::string &file);
        void setHotReloadEnabled(const bool &enabled);
        void setNumberOfBounces(const int &bounces);
        void setRaysPerPixel(const int &rays);
        void setCamera(const std::shared_ptr<Camera> &camera);
        void addObjects(const std::vector<std::shared_ptr<IObject>> &objects);
        void setLights(const std::vector<std::shared_ptr<ALight>> &lights);
        void setRawConfiguration(const std::string &raw);

        // Getters
        bool isMultithreadingEnabled() const;
        const std::vector<std::string> &getClusters() const;
        bool isPreRenderEnabled() const;
        bool isContinuousRenderEnabled() const;
        const std::string &getOutputFile() const;
        bool isHotReloadEnabled() const;
        int getNbBounces() const;
        int getRaysPerPixel() const;
        const Camera &getCamera() const;
        Camera &getCamera();
        std::vector<std::shared_ptr<IObject>> getPool() const;
        std::vector<std::shared_ptr<LightPoint>> getLightPoints() const;
        std::vector<std::shared_ptr<DirectionalLight>> getDirectionalLights() const;
        Vec3 getBackgroundLight() const;
        Vec3 getAmbientLight() const;
        std::string getRawConfiguration() const;
        sf::Vector2u getResolution() const;
        float getAntiAliasing() const;
        const IObject *getClosest(const Ray &ray, const IObject *ignore = nullptr, bool ignoreLightSources = false) const;
        const IObject *getBetween(const Ray &ray, float dst, const IObject *ignore = nullptr, bool ignoreLightSources = false) const;

        // Methods
        void addLightPoint(std::shared_ptr<LightPoint> light);
        void addObject(std::unique_ptr<IObject> &&object);
        void addBackgroundLight(std::shared_ptr<BackgroundLight> light);
        void addAmbientLight(std::shared_ptr<ALight> light);

    protected:
    private:
        std::vector<std::shared_ptr<IObject>> _pool;
        std::vector<std::shared_ptr<DirectionalLight>> _directionalLights;
        std::vector<std::shared_ptr<LightPoint>> _lightsPoints;
        std::string _rawConfig;
        std::shared_ptr<Camera> _camera;
        BackgroundLight _backgroundLight;
        ALight _ambientLight;
        bool _multithreadingEnabled = false;
        std::vector<std::string> _clusters;
        bool _preRenderEnabled = false;
        bool _continuousRenderEnabled = false;
        std::string _outputFile;
        bool _hotReloadEnabled = false;
        int _numberOfBounces = 0;
        int _raysPerPixel = 0;
};
