//JSONReader.cpp
//

#include "JSONReader.h"

namespace json{

	int read(const std::string& filename, std::string* buffer){
		int line = 0;
		
		//Open File
		std::ifstream fin(filename.c_str());
		
		//Check if open
		if(fin.is_open()){
			line = 1;
			while(!fin.eof()){
				std::getline(fin,buffer[line],'\n');
				line++;
			}
		}
		return line-1; //adjust last addition
	}
	
	int extract(const std::string* buffer, int no_lines, int& line_number, Collection& collection){
		//variable
		int result =0;
		int numCollection =0;
		int i = 0;
		
		//For the first run
		if(line_number == 1){
			if(buffer[line_number].empty()){
				//If file is empty
				std::cout << "File is empty\n";
			}else if(buffer[line_number].find("}") < buffer[line_number].length()){
				//If collection is empty 
				//{}
				;
			}else if(buffer[line_number+1].find("}") < buffer[line_number+1].length() && buffer[line_number+1].find("\"") > buffer[line_number+1].length()){
				//if collection is empty
				//{
				//		}
				;
			}else{
				line_number++;
				//Anonymous collection
				
				if(buffer[line_number].find("{") > buffer[line_number].length()){
					//Anonymous collection exist
					//set obj name empty
					collection.collectionName = "";
					i = line_number;
					
					//count how many collections
					while(	buffer[i].find("{") > buffer[i].length() &&
								buffer[i].find("}") > buffer[i].length()){
						numCollection++;
						i++;
					}
				}
			}		
		}
		
		//This point there is no empty file/ empty collection / anonymous collection!
		if(buffer[line_number].find("{") < buffer[line_number].length() && 
			buffer[line_number].find(":") < buffer[line_number].length()){
			//Object exist
			result = 1;
			
			//get object name
			collection.collectionName = buffer[line_number].substr(
				buffer[line_number].find("\""),
				buffer[line_number].find("\"",buffer[line_number].find("\"")+1)-buffer[line_number].find("\"")+1);
			line_number++;
			
			i = line_number;
			while(	buffer[i].find("{") > buffer[i].length() &&
							buffer[i].find("}") > buffer[i].length()){
					numCollection++;
					i++;
				}
		}

		//Assign value and name
		if( numCollection > 0 ){
			for(int i = 0 ; i < numCollection ; i++ ){
			//find all "'s
			int index[4];
			index[0] = buffer[line_number].find("\"");
			index[1] = buffer[line_number].find("\"",index[0]+1);
			index[2] = buffer[line_number].find("\"",index[1]+1);
			index[3] = buffer[line_number].find("\"",index[2]+1);
			
			//get value
			collection.name[i] = buffer[line_number].substr(index[0],index[1]-index[0]+1);
			collection.value[i] = buffer[line_number].substr(index[2],index[3]-index[2]+1);
			
			line_number++;
			}
		}
		
		//Check if next line is the end of the line
		if(	buffer[line_number].find("}") < buffer[line_number].length() &&
			buffer[line_number+1].find("}") < buffer[line_number+1].length()){
			line_number++;
		}	
		
		//Check if next line is the start of new object
		if(buffer[line_number].find("},") < buffer[line_number].length()){
			line_number++;
		}
		
		return result;
	}
	
	int print(const Collection& src){
		int i = 0;
		
		//Object name
		std::cout << src.collectionName <<"\n";
		
		//Collections
		while(src.name[i] != ""){
			std::cout << "          " << src.name[i] << "=>";
			std::cout << src.value[i] << "\n";
			i++;
		}
		
		return i;	
	}


}