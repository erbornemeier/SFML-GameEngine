#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "ResourcePack.h"

ResourcePack::ResourcePack(string rp_name){
    _base_path += rp_name + "/";
    ifstream fin(_base_path + rp_name + ".config");
    if (!fin.is_open()){
        cerr << "ResourcePack at " << _base_path << " not found." << endl;
        throw runtime_error("Resource Pack not Found.");
    }

    _loadTexturesFromFile(fin);

    fin.close();
}

ResourcePack::~ResourcePack(){
    for (auto sprites : _sprite_map) {
        for (auto sprite: sprites.second){
            delete sprite;
        }
    }
}

vector<Sprite*> ResourcePack::getGraphic(const string& graphic_name){
    return _sprite_map[graphic_name];
}

void ResourcePack::_loadTexturesFromFile(ifstream& fin){
    
    while (!fin.eof()){

        //read in a line from the file
        string line;
        getline(fin, line);
        if (line.length() == 0 || line[0] == '#') continue; //skip if commented or empty
        istringstream iss(line);
        
        //extract required 3 values
        string name, type, resource_file;
        iss >> name >> type >> resource_file;

        //handle each type accordingly
        if (type == "Image"){
            _addImageToSpriteMap(name, resource_file);
        }
        else if (type == "Animation"){
            int x, y, w, h, s;
            iss >> x >> y >> w >> h >> s;
            _addAnimatedImageToSpriteMap(name, resource_file, x, y, w, h, s);
        }
        else if (type == "Audio"){
            _addAudioToAudioMap(name, resource_file);
        }
    }
}

void ResourcePack::_addImageToSpriteMap(string name, string resource_file){
    //attempt to load texture from file
    string resource_path = _base_path + "Images/" + resource_file;
    Texture* t = new Texture;
    if (!t->loadFromFile(resource_path)){
        _throw_error("Resource " + name + " could not be found at " + resource_path);
    }

    vector<Sprite*> vec;
    Sprite* s = new Sprite;
    s->setTexture(*t);
    vec.push_back(s);
    _sprite_map[name] = vec;        
}

void ResourcePack::_addAnimatedImageToSpriteMap(string name, string resource_file, 
                                                int x, int y, int w, int h, int stride){
    //TODO: implement animation reading, potential make this a funtion that the above calls
    //with x,y,w,h,stride convering the whole image
}

void ResourcePack::_addAudioToAudioMap(string name, string resource_file){

    //TODO: implement audio reading

}

void ResourcePack::_throw_error(string error_str){
    throw runtime_error(error_str);
}
