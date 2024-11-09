import streamlit as st
from restaurant import Restaurant

def tables_page(restaurant: Restaurant) -> None:
    """
    Renders the Tables page where users can manage tables by adding, taking,
    releasing, or deleting them.

    Parameters:
    - restaurant (Restaurant): The main restaurant object that manages tables.
    """
    st.header("Tables")

    # Dropdown for selecting a table
    table_options = [f"Table {table.name} - {table.seats}" for table in restaurant.tables]
    selected_table = st.selectbox("Table", table_options)

    # Get the selected table object based on the selection
    selected_table_obj = next((table for table in restaurant.tables if f"Table {table.name} - {table.seats}" == selected_table), None)

    # Action buttons in columns
    col1, col2, col3 = st.columns([1, 1, 1])
    with col1:
        if st.button("Take the table"):
            if selected_table_obj:
                selected_table_obj.take()
                st.success(f"{selected_table} is now taken.")
    with col2:
        if st.button("Release the table"):
            if selected_table_obj:
                selected_table_obj.release()
                st.success(f"{selected_table} is now released.")
    with col3:
        if st.button("Delete"):
            if selected_table_obj in restaurant.tables:
                restaurant.tables.remove(selected_table_obj)
                st.success(f"{selected_table} has been deleted.")

    # Divider
    st.write("---")

    # Form to add a new table
    st.subheader("Add a New Table")
    table_name = st.text_input("Name of table")
    table_seats = st.number_input("Number of seats", min_value=1, step=1, value=4)

    if st.button("Add"):
        if table_name:
            restaurant.add_table(table_name, table_seats)
            st.success(f"Table {table_name} with {table_seats} seats added.")
        else:
            st.error("Please enter a name for the table.")