if(CPACK_GENERATOR STREQUAL "NSIS") 
    # NSIS doesn't always like forward slashes 
    file(TO_NATIVE_PATH "${CPACK_NSIS_MUI_HEADERIMAGE}" CPACK_NSIS_MUI_HEADERIMAGE_NATIVE) 
    set(CPACK_NSIS_MUI_HEADERIMAGE "${CPACK_NSIS_MUI_HEADERIMAGE_NATIVE}") 
    file(TO_NATIVE_PATH "${CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP}" CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP_NATIVE) 
    set(CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP "${CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP_NATIVE}") 
endif() 
