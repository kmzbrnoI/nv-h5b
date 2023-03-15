all: panel-nv-h5t.kicad_pcb fab

panel-nv-h5t.kicad_pcb: nv-h5t.kicad_pcb Makefile
	kikit panelize \
		--layout 'grid; rows: 1; cols: 9; space: 3mm' \
		--tabs annotation \
		--cuts 'mousebites; drill: 0.3mm; spacing: 0.6 mm; prolong: 0.5mm' \
		--post 'millradius: 1mm' \
		--source 'tolerance: 10mm' \
		nv-h5t.kicad_pcb panel-nv-h5t.kicad_pcb

fab: panel-nv-h5t.kicad_pcb Makefile
	kikit fab jlcpcb --no-drc panel-nv-h5t.kicad_pcb fab

clean:
	rm panel*
	rm -rf fab

.PHONY: all clean
