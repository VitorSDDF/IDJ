#include <unordered_map>

class Resources{

	public:
		
		SDL_Texture* GetImage (string file);
		void ClearImages();

	private:

		std::unordered_map<std::string,SDL_Texture*> imageTable;

}