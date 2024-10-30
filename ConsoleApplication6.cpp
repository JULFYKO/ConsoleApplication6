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
		if (isOn && volume > 0) {
			volume--;
		}
	}

	void showStatus() {
		std::cout << "\ttv is " << (isOn ? "on" : "off") << "\n\tchannel : " << channel
			<< "\n\tvolume : " << volume << "\n";
	}

};
class Remote
{
private:
	TV* tv;
public:
	Remote(TV* tv = nullptr) : tv(tv) {}

	void setTV(TV* newTV) { tv = newTV; }

	void power() {
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
		if (tv && tv->isOn) {
			tv->channel = ch;
		}
	}




};
int main() {
	TV tv1(10, 30);
	TV tv2(15, 100);

	Remote remote(&tv1);

	remote.power();
	remote.goChannel(5);
	++remote;
	+remote;

	tv1.showStatus();
	std::cout << "\t----------"<<std::endl;
	remote.setTV(&tv2);
	remote.power();
	remote.goChannel(3);
	//--remote;
	//+remote;

	tv2.showStatus();

	return 0;
}

