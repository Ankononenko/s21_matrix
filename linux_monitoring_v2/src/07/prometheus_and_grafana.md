# Report on setting up Prometheus and Grafana

## Prometheus set up:

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
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/01_-_Prometheus_started.png?raw=true" alt="01_-_Prometheus_started.png" width="1000"/>

_Prometheus web UI from virtual machine accessed from local:_ 
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/03_-_Prometheus_web_UI.png" alt="03_-_Prometheus_web_UI.png" width="1000"/>

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
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/02_-_Node_Exporter_started.png?raw=true" alt="02_-_Node_Exporter_started.png" width="1000"/>

_Targets in Prometheus web UI:_ 
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/04_-_Targets_in_Prometheus_web_UI.png" alt="04_-_Targets_in_Prometheus_web_UI.png" width="1000"/>

## Grafana set up:

### 1. Make sure that the dependencies are installed:
`$ sudo apt-get install -y apt-transport-https software-properties-common`

### 2. Add GPG key:

`$ get -q -O - https://packages.grafana.com/gpg.key | sudo apt-key add -`

### 3. Add this repository for stable releases:
`$ echo "deb https://packages.grafana.com/oss/deb stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list`

### 4. Update and install Grafana:

`$ udo apt-get update`\
`$sudo apt-get -y install grafana`

### 5. Start Grafana:

`$sudo systemctl enable grafana-server` - To automatically start the Grafana after reboot. \
`$sudo systemctl start grafana-server` - To start the Grafana. \
`$sudo systemctl status grafana-server` - To check the status of Grafana.

_Grafana service running:_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/05_-_Grafana_service_running.png" alt="05_-_Grafana_service_running.png" width="1000"/>

_Grafana web UI from virtual machine accessed from local:_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/06_-_Grafana_web_UI.png" alt="06_-_Grafana_web_UI.png" width="1000"/>

_Datasource created, Grafana dashboard imported:_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/07_-_Grafana_dashboard_imported.png" alt="07_-_Grafana_dashboard_imported.png" width="1000"/>

## Exploring Grafana:

_Metrics added (CPU, available RAM, free space and the number of I/O operations on the hard disk, space used, network traffic):_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/08_-_Metrics%20added.png?raw=true" alt="09_-_Script_from_part_2_runned.png" width="1000"/>

_Script to fill up the free disk space of the server up to 1GB left completed:_ \
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/09_-_Script_from_part_2_runned.png" alt="09_-_Script_from_part_2_runned.png" width="1000"/>

## Stress utility: 

### Install the utility:
`$ sudo apt install -y stress`

### Run Stress utility and observe the result:
`$ stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s`

<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/10_-_Stress_utility_runned.png" alt="10_-_Stress_utility_runned.png" width="1000"/>
<img src="https://github.com/finchren/School21_main_education/blob/main/linux_monitoring_v2/src/screenshots/11_-_Result_of_Stress_utility_run.png" alt="11_-_Result_of_Stress_utility_run.png" width="1000"/>
