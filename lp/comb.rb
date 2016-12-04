def con(indice,parte)
	for i in 0..cad.length
		print "#{parte}#{cad[i]}"
		if indice!=namespace : do
			con(indice+1,parte+cad[i])
		end
print "n: "
@n=gets
print "cad: "
@cad=gets
con(0,"")
