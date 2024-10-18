# Create a loop to iterate over all registers

define dump_ucdm_registers
    set logging enabled on
    set logging file dmap_export.log
    set logging overwrite on

    printf "Index, Data, Ptr, AccessType, RWH, BWH\n"

    # Loop through each element of the register array
    set $i = 0
    while($i++ < 255)
        printf "Register %d", $i

        set $register = ucdm_register[$i]

        printf "data:"
        printf "0x%x", $register.data  

        printf "ptr:"
        info symbol $register.ptr  
        
        printf "acctype:"
        printf "0x%x", ucdm_acctype[$i]

        set $rwh_ptr = (avlt_node_t *) avlt_find_node(&ucdm_rwht, $i) 
        if ($rwh_ptr != 0)
            printf "rwh:"
            info symbol $rwh_ptr->content
        end

        set $bwh_ptr = (avlt_node_t *) avlt_find_node(&ucdm_bwht, $i) 
        if ($bwh_ptr != 0)
            printf "bwh:"
            info symbol $bwh_ptr->content
        end
    end
    set logging enabled off
    set logging overwrite off
end
