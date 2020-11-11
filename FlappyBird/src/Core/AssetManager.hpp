#ifndef __ASSET_MANAGER_HPP_INCLUDED__
#define __ASSET_MANAGER_HPP_INCLUDED__

#include <map>
#include <filesystem>

#include <SFML/Graphics.hpp>

namespace Core
{
	class AssetManager
	{
	private:
		template<typename _T>
		void _loadObj(std::map<std::string, _T>& map, const std::string& name, const std::filesystem::path& path)
		{
			if (!map.contains(name))
				if (_T object; object.loadFromFile(path.string()))
					map.emplace(name, std::move(object));
		}

	public:
		[[nodiscard]] inline auto& getTexture(const std::string& name) const { return m_textures.at(name); }

		[[nodiscard]] inline auto& getFont(const std::string& name) const { return m_fonts.at(name); }

		inline void loadTexture(const std::string& name, const std::filesystem::path& path) { _loadObj<sf::Texture>(m_textures, name, path); }

		inline void loadFont(const std::string& name, const std::filesystem::path& path) { _loadObj<sf::Font>(m_fonts, name, path); }

	private:
		std::map<std::string, sf::Texture> m_textures;
		std::map<std::string, sf::Font>    m_fonts;
	};
} // namespace Core

#endif /* !__ASSET_MANAGER_HPP_INCLUDED__ */