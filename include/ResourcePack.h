#include <map>
#include <string>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef _Resource_Pack
#define _Resource_Pack

class ResourcePack{
    public:
        ResourcePack(string rp_name = "default");
        ~ResourcePack();
        vector<Sprite*> getGraphic(const string& graphic_name);

    private:
        void _loadTexturesFromFile(ifstream& fin);
        void _addImageToSpriteMap(string name, string resource_file);
        void _addAnimatedImageToSpriteMap(string name, string resource_file, 
                                          int x, int y, int w, int h, int stride);
        void _addAudioToAudioMap(string name, string resource_file);                                

        void _throw_error(string error_str);

    private:    
        string _base_path = "resource_packs/";
        string _rp_name;
        map<string, vector<Sprite*> > _sprite_map;
        //TODO: add audio map

};

#endif