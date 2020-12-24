#ifndef RAW_DATA_OBSERVER_PLUGIN_H
#define RAW_DATA_OBSERVER_PLUGIN_H

#include <QObject>

class SkydelRuntimeRawDataObserver : public QObject
{
public:
  virtual ~SkydelRuntimeRawDataObserver() = default;

  struct TimedRawData
  {
    int64_t time;            // ms
    // More members to follow here
  };

  virtual void pushRawData(const TimedRawData &) = 0;
  virtual void connectToView(QWidget* view) = 0;
};


class SkydelRawDataObserverInterface
{
public:
  virtual ~SkydelRawDataObserverInterface() = default;

  virtual SkydelRuntimeRawDataObserver* createRuntimePositionObserver() = 0;

  static constexpr auto ID = "SkydelRawDataObserver";
  static constexpr auto VERSION = 1;
};


#endif
