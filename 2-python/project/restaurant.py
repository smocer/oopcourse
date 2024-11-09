from datetime import datetime, timedelta

class Table:
    def __init__(self, name, seats):
        self.name = name
        self.seats = seats
        self.is_occupied = False

    def take(self):
        self.is_occupied = True

    def release(self):
        self.is_occupied = False

class Booking:
    def __init__(self, guest_name, phone, start_time, end_time, table):
        self.guest_name = guest_name
        self.phone = phone
        self.start_time = start_time
        self.end_time = end_time
        self.table = table

class Restaurant:
    def __init__(self):
        self.tables = []
        self.bookings = []

    def add_table(self, name, seats):
        table = Table(name, seats)
        self.tables.append(table)

    def find_free_table(self, seats_needed):
        for table in self.tables:
            if not table.is_occupied and table.seats >= seats_needed:
                return table
        return None

    def add_booking(self, guest_name, phone, start_time, end_time, seats_needed):
        table = self.find_free_table(seats_needed)
        if table:
            table.take()
            booking = Booking(guest_name, phone, start_time, end_time, table)
            self.bookings.append(booking)
            return booking
        else:
            return None  # No available table

    def current_status(self):
        return [(booking.guest_name, booking.table.name, booking.start_time, booking.end_time)
                for booking in self.bookings]
