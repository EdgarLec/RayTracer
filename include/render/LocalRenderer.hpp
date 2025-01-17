/*
** EPITECH PROJECT, 2023
** Epitech-Raytracer
** File description:
** LocalRenderer
*/

#ifndef EPITECH_RAYTRACER_LOCALRENDERER_HPP
#define EPITECH_RAYTRACER_LOCALRENDERER_HPP

#include "IRenderer.hpp"
#include "lights/DirectionalLight.hpp"

namespace Raytracer {

    /**
     * @brief This class is responsible for rendering the scene locally.
     *
     * It will render the scene using the CPU.
     */
    class LocalRenderer : public IRenderer {
    public:
        LocalRenderer(sf::Vector2u start, sf::Vector2u end);

        void render(const Scene &scene, PointArray &array, sf::Time *time) override;

        std::pair<sf::Vector2u, sf::Vector2u> getRange() const override;

        int getThreadsCount() const override;

        void setRange(sf::Vector2u start, sf::Vector2u end) override;

        void reset() override;

        const std::vector<std::unique_ptr<IRenderer>> &getSubRenderers() override;

    private:
        void internalSetRange(sf::Vector2u start, sf::Vector2u end);
        void addPixel(sf::Vector2u pos, Vec3 color);
        Vec3 getPixelFColor(sf::Vector2f pos, const Scene &pool);
        Vec3 addLights(const Vec3 &normal, const Vec3 &inter, const Vec3 &color, const Scene &pool, const IObject *obj);

        PointArray *_array;
        sf::Vector2u _start, _end;
        int _nbFrames{};
        std::vector<std::unique_ptr<IRenderer>> _subRenderers;
    };
} // Raytracer

#endif //EPITECH_RAYTRACER_LOCALRENDERER_HPP
