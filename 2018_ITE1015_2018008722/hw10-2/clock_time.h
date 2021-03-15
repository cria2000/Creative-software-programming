#ifndef CLOCK_TIME_H
#define CLOCK_TIME_H

// Define a set of symbolic constants used to specify various values related
// to time keeping.
#define SECONDS_PER_MINUTE      60
#define MINUTES_PER_HOUR        60
#define HOURS_PER_DAY           24

class ClockTime
// ClockTime is a concrete identity class used to keep track of current
// time as it is moves forward.  Note that time cannot be regressed.
//
// NOTE: Copying an instance of this class is bit-wise.
{
public:
  ClockTime ();

  ClockTime (int hour, int minute, int second, int secondsPerTick);

  ~ClockTime ()
  { hour_ = minute_ = second_ = secondsPerTick_ = startTime_ = 0; }

  int const hour () const { return hour_; }
  int const minute () const { return minute_; }
  int const second () const { return second_; }
  int const secondsPerTick () const { return secondsPerTick_; }

  unsigned int startTime () const { return startTime_; }
  unsigned int deltaTime () const { return deltaTime_; }

  void setTime (ClockTime const& initialTime)
  {
    hour_ = initialTime.hour_;
    minute_ = initialTime.minute_;
    second_ = initialTime.second_;
    secondsPerTick_ = initialTime.secondsPerTick_;
    deltaTime_ = 0;
  }

  void setTime (int hour, int minute, int second, int secondsPerTick)
  {
    hour_ = hour;
    minute_ = minute;
    second_ = second;
    secondsPerTick_ = secondsPerTick;
    deltaTime_ = 0;
  }

  void reset ();

  void increment ();

  void display () const;

private:
  int hour_;
  int minute_;
  int second_;
  int secondsPerTick_;
  unsigned int startTime_;
  unsigned int deltaTime_;

  void recordStartTime ();
};

class Clock{
	protected: 
		ClockTime _clockTime;
		double _driftPerSecond;
		double _totalDrift;
		Clock(int hour, int minute, int second, double driftPerSecond);
	public:
		void reset();
		void tick();
		virtual void displayTime()=0;
};
class NaturalClock :public Clock{
	protected:
		NaturalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond){};
};
class MechanicalClock : public Clock{
	protected: 
		MechanicalClock(int hour, int minute, int second, double driftPerSecond) :  Clock(hour, minute, second, driftPerSecond){};
};
class DigitalClock : public Clock{
	protected:
		DigitalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond){};
};
class QuantumClock : public Clock{
	protected:
		QuantumClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond){};
};
class SundialClock : public NaturalClock{
	public :
		SundialClock(int hour, int minute, int second) : NaturalClock(hour, minute, second, 0.0){};
		virtual void displayTime();
};
class CuckooClock : public MechanicalClock{
	public :
		CuckooClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0.000694444){};
		virtual void displayTime();
};
class GrandFatherClock : public MechanicalClock{
	public :
		GrandFatherClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0.000347222){};
		virtual void displayTime();
};
class WristClock : public DigitalClock{
	public :
		WristClock(int hour, int minute, int second) : DigitalClock(hour, minute, second, 0.000034722){};
		virtual void displayTime(); 
};
class AtomicClock : public QuantumClock{
	public :
		AtomicClock(int hour, int minute, int second) : QuantumClock(hour, minute, second, 0.0){};
		virtual void displayTime();
};

#endif  // CLOCK_TIME_H
