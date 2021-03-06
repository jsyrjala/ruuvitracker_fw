require('gsm')
require('tracker_api')

gps_enabled = 0
gps_uart = 1

function gps_enable()
	uart.setup( gps_uart, 115200, 8, uart.PAR_NONE, uart.STOP_1 )
	gsm_cmd('AT+CGPSPWR=1')
	gsm_cmd('AT+CGPSRST=0')
	gps_enabled = 1
end

function gps_parse_rmc(line)
			local time, status, latitude, ns_indicator, longitude,
			ew_indicator, speed = line:match("^%$GPRMC,([^,]*),([^,]*),([^,]*),([^,]*),([^,]*),([^,]*),([^,]*)")
			if status == "A" then print("Status: Valid location")
			else print ("Not valid location") return end
			latitude = latitude..','..ns_indicator
			longitude = longitude..','..ew_indicator
			print("Time: " ..time)
			print("Status: "..status)
			print("Lat:" ..latitude)
			print("Lon:" ..longitude)
			print("Sending event")
			local event={}
			--Get first timestamp as a session_code
			session_code = session_code or time
			event.version="1"
			event.latitude = latitude
			event.longitude = longitude
			event.session_code = session_code
			send_event(event)
end

function gps_looper()
	if gps_enabled==0 then gps_enable() end

	print("Starting GPS loop. Press 'q' to stop")	
	while 1 == 1 do
		local str = uart.read(gps_uart,'*l')
		if str:find("^%$GPRMC") then gps_parse_rmc(str)	end
		if str~="" then print(str) end
		
		q = uart.read(0,'*l',uart.NO_TIMEOUT)
		if q == "q" then break end
	end
end
