import streamlit as st
from restaurant import Restaurant
from datetime import datetime, timedelta

def booking_page(restaurant: Restaurant) -> None:
    """
    Renders the Booking page where users can create bookings for tables.

    Parameters:
    - restaurant (Restaurant): The main restaurant object that manages tables and bookings.
    """
    st.header("Booking")

    # Booking form
    with st.form("booking_form"):
        guest_name = st.text_input("Input name")
        phone = st.text_input("Input phone")

        # Layout for time selection
        col1, col2 = st.columns([1, 1])
        with col1:
            start_time = st.time_input("From")
        with col2:
            period = st.number_input("Period", min_value=0, step=1)

        # Dropdown for selecting a table
        table_options = [f"Table {table.name} - {table.seats} seats" for table in restaurant.tables if not table.is_occupied]
        selected_table = st.selectbox("Select table", table_options)

        # Submit button for booking form
        if st.form_submit_button("Submit"):
            # Combine date with start time for full datetime
            start_datetime = datetime.combine(datetime.today(), start_time)
            end_datetime = start_datetime + timedelta(hours=period)
            
            # Attempt to book the selected table
            selected_table_obj = next((table for table in restaurant.tables if f"Table {table.name} - {table.seats} seats" == selected_table), None)
            if selected_table_obj:
                booking = restaurant.add_booking(guest_name, phone, start_datetime, end_datetime, selected_table_obj.seats)
                if booking:
                    st.success(f"Booking created for {guest_name} at table {selected_table}.")
                else:
                    st.error("Failed to create booking.")

    # Divider
    st.write("---")

    # Display the status of tables
    st.subheader("Tables Status")
    for table in restaurant.tables:
        col1, col2, col3 = st.columns([3, 1, 1])
        with col1:
            status = "Free" if not table.is_occupied else "Occupied"
            st.write(f"{table.name} - {table.seats} seats")
        with col2:
            st.write(status)
        with col3:
            if st.button("Delete", key=f"delete_{table.name}"):
                restaurant.tables.remove(table)
                st.success(f"{table.name} deleted.")