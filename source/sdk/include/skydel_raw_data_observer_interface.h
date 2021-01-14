#ifndef RAW_DATA_OBSERVER_PLUGIN_H
#define RAW_DATA_OBSERVER_PLUGIN_H

#include <QObject>

class SkydelRuntimeRawDataObserver : public QObject
{
public:
  virtual ~SkydelRuntimeRawDataObserver() = default;

  struct SignalRawData
  {
      SignalRawData():
          signalType("Unknown"),
          pseudoRange(0.0),
          phaseRange(0.0),
          pseudoRangeRate(0.0),
          phaseRangeRate(0.0),
          ageSeconds(0.0)
      {}

      std::string signalType;

      double pseudoRange;
      double phaseRange;
      double pseudoRangeRate;
      double phaseRangeRate;

      unsigned long ageSeconds;
  };

  struct SatelliteRawData
  {
      SatelliteRawData():
          sys("Unknown"),
          id (0),
          subId(0)
      {}

      std::string sys;
      int id;
      int subId; // GLONASS: frequency slot [-7, +6]

      std::vector<SignalRawData> signalsData;
  };


  struct TimedRawData
  {
      TimedRawData():
          time(0)
      {}

      int64_t time;
      std::vector<SatelliteRawData> satellitesData;
  };

  virtual void pushRawData(const TimedRawData &) = 0;
  virtual void connectToView(QWidget* view) = 0;
};


class SkydelRawDataObserverInterface
{
public:
  virtual ~SkydelRawDataObserverInterface() = default;

  virtual SkydelRuntimeRawDataObserver* createRuntimeRawDataObserver() = 0;

  static constexpr auto ID = "SkydelRawDataObserver";
  static constexpr auto VERSION = 1;
};


#endif
