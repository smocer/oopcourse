import streamlit as st
from restaurant import Restaurant
from pages.status_page import status_page
from pages.tables_page import tables_page
from pages.booking_page import booking_page

if 'restaurant' not in st.session_state:
    st.session_state['restaurant'] = Restaurant()

restaurant = st.session_state['restaurant']

page = st.sidebar.radio("Navigation", ["Booking", "Tables", "Status"])

if page == "Booking":
    booking_page(restaurant)

elif page == "Tables":
    tables_page(restaurant)

elif page == "Status":
    status_page(restaurant)
