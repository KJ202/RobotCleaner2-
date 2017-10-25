#include "../include/state.hpp"
#include "../include/world.hpp"

namespace cleaner{
  state::state(std::vector<bool>const grid, bool base, size battery, size pose, size width, size height): grid(grid), base(base), battery(battery), pose(pose), width(width),height(height){}

  state::~state(){}

  std::vector<bool>const& state::getGrid() const{
    return grid;
  }

  bool state::getBase() const{
    return base;
  }

  size state::getBattery() const{
    return battery;
  }

  size state::getPose() const{
    return pose;
  }

  int state::getBaseDistance(){
    /*for simplicity basePosition = 0*/
    int b = 0;
    int i;
    int dist;
    for(i=1; i<= height;++i){
    	if(pose < i*width && i == 1){
    		dist = pose - b ;
    		break; 	
    	}
    	else if (pose < i*width){
    		dist = (pose- (i-1)*width) + i;
    		break;
    	}
    }
    return dist;
  }

/*
* for now on 2 features only 
* battery level 
* and distance to the base 
* so the length of the vector is NBF*len(action) for now on its 14
* 
*/

  
  std::vector<double> state::getFeatures(int a){

    std::vector<double> features;
    features.assign(this->NBF*action::END,0.0);
    
    features[a] = battery;
    features[a+1] = this->getBaseDistance();

    return features;
  }
}
