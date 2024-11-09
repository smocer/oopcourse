import streamlit as st
from restaurant import Restaurant

def status_page(restaurant: Restaurant) -> None:
    """
    Renders the Status page where users can view the current availability
    and status of all tables in the restaurant.

    Parameters:
    - restaurant (Restaurant): The main restaurant object that manages tables and bookings.
    """
    # Display header
    st.header("Status")

    # Display each table's status
    free_tables = 0
    free_seats = 0

    for table in restaurant.tables:
        status = "Free" if not table.is_occupied else "Occupied"
        st.write(f"{table.name} - {table.seats} seats   {status}")

        # Count free tables and seats
        if not table.is_occupied:
            free_tables += 1
            free_seats += table.seats

    # Divider
    st.write("---")

    # Display summary of free tables and seats
    st.write(f"Number of free tables - {free_tables}")
    st.write(f"Number of free seats - {free_seats}")