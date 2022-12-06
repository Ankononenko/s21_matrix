## Report on setting up Prometheus and Grafana

### 1. Create system user:
`$ sudo useradd --system --no-create-home --shell /bin/false prometheus`

`--system` - Will create a system account. \
`--no-create-home` - We don't need a home directory for Prometheus or any other system accounts in our case. \
`--shell /bin/false` - It prevents logging in as a Prometheus user. \
`prometheus` - Will create Prometheus user and a group with the exact same name.

### 2. Download Prometheus:

`$ wget https://github.com/prometheus/prometheus/releases/download/v2.32.1/prometheus-2.32.1.linux-amd64.tar.gz`

### 3. Extract:

`$ tar -xvf prometheus-2.32.1.linux-amd64.tar.gz`

### 4. Create a data directory for Prometheus and move the unpacked files there:

`$ sudo mkdir -p /data /etc/prometheus` \
`$ cd prometheus-2.32.1.linux-amd64` \
`$ sudo mv prometheus promtool /usr/local/bin/` \
`$ sudo mv prometheus.yml /etc/prometheus/prometheus.yml` 

### 5. To avoid permission issues, you need to set correct ownership for the /etc/prometheus/ and data directory:

`$ sudo chown -R prometheus:prometheus /etc/prometheus/ /data/`

### 6. Check that the Prometheus was installed successfully and delete the no longer needed archive and folder: 

`$ prometheus --version` \
`$ cd ..` \
`$ rm -rf prometheus*`

### 7. We're going to use systemd, which is a system and service manager for Linux operating systems. For that, we need to create a systemd unit configuration file:

`$ sudo vim /etc/systemd/system/prometheus.service`

_prometheus.service:_

```
[Unit]
Description=Prometheus
Wants=network-online.target
After=network-online.target

StartLimitIntervalSec=500
StartLimitBurst=5

[Service]
User=prometheus
Group=prometheus
Type=simple
Restart=on-failure
RestartSec=5s
ExecStart=/usr/local/bin/prometheus \
  --config.file=/etc/prometheus/prometheus.yml \
  --storage.tsdb.path=/data \
  --web.listen-address=0.0.0.0:9090 \
  --web.enable-lifecycle

[Install]
WantedBy=multi-user.target
```
`--config.file=/etc/prometheus/prometheus.yml` - Path to the main Prometheus configuration file. \
`--storage.tsdb.path=/data` - Location to store Prometheus data. \
`--web.listen-address=0.0.0.0:9090` - Configure to listen on all network interfaces. \
`--web.enable-lifecycle` - Allows to manage Prometheus, for example, to reload configuration without restarting the service.

### 8. Start Prometheus:

`$ sudo systemctl enable prometheus` - To automatically start the Prometheus after reboot. \
`$ sudo systemctl start prometheus` - Start the Prometheus. \
`$ sudo systemctl status prometheus` - Check the status of the service.

_Prometheus service running:_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/01_-_Prometheus_started.png?raw=true" alt="01_-_Prometheus_started.png" width="800"/>
