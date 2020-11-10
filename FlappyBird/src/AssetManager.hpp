#ifndef __ASSET_MANAGER_HPP_INCLUDED__
#define __ASSET_MANAGER_HPP_INCLUDED__

#include <map>
#include <filesystem>

#include <SFML/Graphics.hpp>

namespace Core
{
	class AssetManager
	{
	public:

		[[nodiscard]] inline auto& getTexture(const std::string& name) const { return m_textures.at(name); }

		void loadTexture(const std::string& name, const std::filesystem::path path);

	private:
		std::map<std::string, sf::Texture> m_textures;

	};
} // namespace Core

#endif /* !__ASSET_MANAGER_HPP_INCLUDED__ */