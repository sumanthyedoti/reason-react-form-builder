module Delete = {
  [@react.component]
  let make = (~width=20, ~height=20) =>
    <svg
      xmlns="http://www.w3.org/2000/svg"
      width={string_of_int(width)}
      height={string_of_int(height)}
      viewBox="0 0 24 24"
      fill="none"
      stroke="currentColor"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round">
      <path
        stroke="currentColor"
        d="M3 6h18M19 6v14a2 2 0 01-2 2H7a2 2 0 01-2-2V6m3 0V4a2 2 0 012-2h4a2 2 0 012 2v2M10 11v6M14 11v6"
      />
    </svg>;
};

module Text = {
  [@react.component]
  let make = (~width=20, ~height=20) =>
    <svg
      width={string_of_int(width)}
      height={string_of_int(height)}
      xmlns="http://www.w3.org/2000/svg"
      viewBox="0 0 512 440">
      <path
        fill="none"
        stroke="currentColor"
        strokeLinecap="round"
        strokeLinejoin="round"
        strokeWidth={string_of_int(40)}
        d="M32 415.5l120-320 120 320m-42-112H74m252-64c12.19-28.69 41-48 74-48h0c46 0 80 32 80 80v144"
      />
      <path
        d="M320 358.5c0 36 26.86 58 60 58 54 0 100-27 100-106v-15c-20 0-58 1-92 5-32.77 3.86-68 19-68 58z"
        fill="none"
        stroke="currentColor"
        strokeLinecap="round"
        strokeLinejoin="round"
        strokeWidth={string_of_int(40)}
      />
    </svg>;
};

module Scale = {
  [@react.component]
  let make = (~width=30, ~height=20) =>
    <svg
      viewBox="0 0 500 240"
      width={string_of_int(width)}
      height={string_of_int(height)}
      xmlns="http://www.w3.org/2000/svg">
      <path
        fill="currentColor"
        d="M429 119.652C378.71 81.937 318.887 62 256 62S133.29 81.938 83 119.652a15.017 15.017 0 00-5.852 9.887 15.024 15.024 0 002.86 11.129l79.183 105.344A14.982 14.982 0 00171.195 252c3.13 0 6.29-.977 8.989-3 22.039-16.527 48.254-25.266 75.816-25.266 27.559 0 53.777 8.739 75.816 25.266 6.622 4.969 16.016 3.629 20.989-2.988l79.183-105.344A15.006 15.006 0 00429 119.652zm-91.594 96.918c-20.234-12.382-42.781-19.882-66.406-22.117v-45.719c0-8.285-6.715-15-15-15s-15 6.715-15 15v45.72c-23.625 2.233-46.172 9.733-66.406 22.116l-61.324-81.586C155.648 106.816 204.688 92 256 92s100.352 14.816 142.73 42.984zm0 0"
      />
    </svg>;
};