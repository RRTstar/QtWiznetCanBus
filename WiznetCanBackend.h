#ifndef WIZNET_CAN_BACKEND_H_
#define WIZNET_CAN_BACKEND_H_

#include <QCanBusDevice>
#include <QUdpSocket>

#include "hw.h"


class WiznetCanBackend : public QCanBusDevice
{
    Q_OBJECT
public:
    WiznetCanBackend(quint16 localPort, const QHostAddress& remoteAddr,
                     quint16 remotePort);

    bool writeFrame(const QCanBusFrame& frame) override;
    QString interpretErrorFrame(const QCanBusFrame& errorFrame) override;

    static QList<QCanBusDeviceInfo> interfaces();

    uint32_t canDriverAvailable(void);
    bool     canDriverFlush(void);
    uint8_t  canDriverRead(void);
    uint32_t canDriverWrite(uint8_t *p_data, uint32_t length);

    QCanBusDevice::CanBusStatus canGetStatus();
protected:
    bool open() override;
    void close() override;
    void timerEvent(QTimerEvent*) override;

private:
    quint16 localPort_;
    QHostAddress remoteAddr_;
    quint16 remotePort_;
    QUdpSocket sock_;
    int timerId_;
    void handlePacket(const QByteArray& data);

    cmd_can_t cmd_can;
    cmd_can_driver_t cmd_can_driver;
    uint8_t cmd_can_buf[512*1024];
    qbuffer_t cmd_can_q;

    qint64 offset_time;
    uint32_t ping_cnt;
    bool     is_connected;
    CanBusStatus can_bus_status;

private slots:
    void dataAvailable();
//    void outQueueTimer();
};

#endif 
