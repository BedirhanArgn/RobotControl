#pragma once
class Pose
{
private:
	float x;
	float y;
	float th;
public:
	Pose();
	float getX();
	void setX(float);
	float getY();
	void setY(float);
	void setTh(float);
	float getTh();
	bool operator==(const Pose&);
	Pose operator+(const Pose&);
	Pose operator-(const Pose&);
	Pose& operator-=(const Pose&);
	Pose& operator+=(const Pose&);
	bool operator<(const Pose&);
	void getPose(float& _x, float& _y, float& _th);
	void setPose(float _x, float _y, float _th);
	float findDistanceTo(Pose);
	float findAngleTo(Pose);
	~Pose();
};

