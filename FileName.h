#pragma once
#include<iostream>
class TV
{
	friend class Remote;
private:
	bool isOn;
	int volume;
	int channel;
	size_t numChannels;
	size_t maxVolume;
public:
	TV(int numChannels = 100, int maxVolume = 50)
		: isOn(false), volume(0), channel(1), numChannels(numChannels), maxVolume(maxVolume) {}

	void power() { isOn = !isOn; }

	void nextChannel() {
		if (isOn) {
			channel = (channel % numChannels) + 1;
		}
	}
	void prevChannel() {
		if (isOn) {
			channel = (channel - 2 + numChannels) % numChannels + 1;
		}
	}
	void incVolume() {
		if (isOn and volume < maxVolume) {
			volume++;
		}
	}
	void decVolume() {
		if (isOn and volume < maxVolume) {
			volume--;
		}
	}
	void showStatus() {
		std::cout << "\ttv is " << (isOn ? "on" : "off") << "\n\tchannel : " << channel << "\n\tvolume : " << volume;
	}
};
class Remote
{
private:
	TV* tv;
public:
	Remote(TV* tv = nullptr) : tv(tv) {}

	void setTV(TV* newTV) { tv = newTV; }

	void power(){
		if (tv) {
			tv->power();
		}
	}
	void operator++() {
		if (tv) {
			tv->nextChannel();
		}
	}

	void operator--() {
		if (tv) {
			tv->prevChannel();
		}
	}

	void operator+() {
		if (tv) {
			tv->incVolume();
		}
	}

	void operator-() {
		if (tv) {
			tv->decVolume();
		}
	}
	void goChannel(int ch) {
		if (tv && tv->isOn && ch > 0 && ch <= tv->numChannels) {
			tv->channel = ch;
		}
	}


};
