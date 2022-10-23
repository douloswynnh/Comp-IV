#include "RandWriter.h"

RandWriter::RandWriter(std::string text, int k){
	std::srand(time(NULL));
	
	if (text.length()== 0 || k<0){
		throw std::invalid_argument("Empty String");
	}
	this->text = text;
	inputText = text; 
	this->k = k;
	bool found = false;
	inputText += inputText.substr(0, k);
	
	for(int i= 0; i<=inputText.length()-k -1; i++){
		for (auto &key : kgramMap){
			if (key.first == inputText.substr(i, k) && key.second.first == inputText.at(i + k)){
				key.second.second++;
				found = true;
			}
		}
		if(!found ){
			kgramMap.insert({inputText.substr(i,k), {inputText.at(i+k), 1}});
		}
		found = false;
	}
}

int RandWriter::orderK(){
	return k;
}

int RandWriter::freq(std::string k_gram, char c){
	int charFrequency = 0;
	
	if(k_gram.length() != k){
		throw std::runtime_error("Kgram is less or greater than order k");
	}
	
	if(k == 0){
		for (int i = 0; i< inputText.length()-1; ++i){
			if(inputText.at(i) == c){
				charFrequency++;
			}
		}
	}
	else {
		for (auto &key : kgramMap){
			if (key.first == k_gram){
				if(c == key.second.first){
					charFrequency = key.second.second;
				}
			}
		}
	}
	return charFrequency;
}

int RandWriter::freq(std::string k_gram){
	int frequency = 0;
	if (k_gram.length() != k){
		throw std::runtime_error("kgram is less than or greater than order k");
	}
	else {
		for (auto &key : kgramMap){
			if (key.first == k_gram){
				frequency += key.second.second;
			}
		}
	}
	return frequency++;
}

char RandWriter::kRand(std::string k_gram){
	std::vector<char> charFreq;
	
	if (k_gram.length() != k){
		throw std::runtime_error("kgram is not length of k");
		
	}
	auto iter = kgramMap.find(k_gram);
	
	if(iter == kgramMap.end()){
		throw std::runtime_error("No kgram found in given text");
	}
	
	for (auto &key: kgramMap){
		if(key.first == k_gram){
			for (int i = 0; i< key.second.second; ++i){
				charFreq.push_back(key.second.first);
			}
		}
	}
	return charFreq.at(rand() %charFreq.size());
	
}

std::string RandWriter::generate(std::string k_gram, int L){
	std::string outputText = k_gram;
	std::string temp = k_gram;
	char chartemp;
	for (int i = 0; i< L - k_gram.length(); ++i){
		chartemp = kRand(temp);
		outputText += chartemp;
		temp = temp.substr(1,k) + chartemp;
	}
	return outputText;
}

std::ostream& operator << (std::ostream& output, RandWriter &karnov){
	output << "Order of: " << karnov.k << "\n";
	output << "   Input: " << karnov.text << "\n";
	//output << " Output: " << karnov.generate(karnov.inputText.substr(0, karnov.k), karnov.output(Length);
	for(auto &key : karnov.kgramMap){
		output << key.first << "Freq:" << karnov.freq(key.first) << "Next character: " 
		<< key.second.first << "with freq of: " << key.second.second << std::endl;
	}
	return output;
}










