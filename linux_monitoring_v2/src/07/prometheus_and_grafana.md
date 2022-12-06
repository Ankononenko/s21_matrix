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

_Prometheus web UI from virtual machine accessed from local:_ 
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/03_-_Prometheus_web_UI.png" alt="03_-_Prometheus_web_UI.png" width="800"/>

## Node Exporter set up:

_Node Exporter is used to collect Linux system metrics like CPU load and disk I/O. Node Exporter will expose these as Prometheus-style metrics._

### 1. Create system user:
`$ sudo useradd --system --no-create-home --shell /bin/false node_exporter`

### 2. Download Node Exporter:

`$ sudo useradd --system --no-create-home --shell /bin/false node_exporter`

### 3. Extract:

`$ tar -xvf node_exporter-1.3.1.linux-amd64.tar.gz`

### 4. Move and clean up the files:

`$ sudo mv node_exporter-1.3.1.linux-amd64/node_exporter /usr/local/bin/` \
`$ rm -rf node_exporter*`

### 5. Check that it has installed:

`$ node_exporter --version`

### 6. Systemd unit file for the service:

`$ sudo vim /etc/systemd/system/node_exporter.service`

_node_exporter.service_

```
[Unit]
Description=Node Exporter
Wants=network-online.target
After=network-online.target

StartLimitIntervalSec=500
StartLimitBurst=5

[Service]
User=node_exporter
Group=node_exporter
Type=simple
Restart=on-failure
RestartSec=5s
ExecStart=/usr/local/bin/node_exporter \
    --collector.logind

[Install]
WantedBy=multi-user.target
```

### 8. Start Node Exporter:

`$ sudo systemctl enable node_exporter` - To automatically start the Node Exporter after reboot, enable the service. \
`$ sudo systemctl start node_exporter` - Start the Node Exporter. \
`$ sudo systemctl status node_exporter` - Check the status of Node Exporter. 

_Node Exporter service running:_ 
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/02_-_Node_Exporter_started.png?raw=true" alt="02_-_Node_Exporter_started.png" width="800"/>

## Grafana set up:

1. 
