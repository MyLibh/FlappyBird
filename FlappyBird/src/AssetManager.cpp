// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "AssetManager.hpp"

namespace Core
{
	void AssetManager::loadTexture(const std::string& name, const std::filesystem::path path)
	{
		if (sf::Texture texture; texture.loadFromFile(path.string()))	
			m_textures.emplace(name, std::move(texture));
	}
} // namespace Core